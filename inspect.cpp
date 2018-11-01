
int Rtabmap::detectMoreLoopClosures(float clusterRadius, float clusterAngle, int iterations, const ProgressState * processState)
{
	UASSERT(iterations>0);

	if(_graphOptimizer->iterations() <= 0)
	{
		UERROR("Cannot detect more loop closures if graph optimization iterations = 0");
		return -1;
	}
	if(!_rgbdSlamMode)
	{
		UERROR("Detecting more loop closures can be done only in RGBD-SLAM mode.");
		return -1;
	}

	std::list<Link> loopClosuresAdded;
	std::multimap<int, int> checkedLoopClosures;

	std::map<int, Transform> poses;
	std::multimap<int, Link> links;
	std::map<int, Signature> signatures;
	this->getGraph(poses, links, true, true, &signatures);

	//remove all invalid or intermediate nodes
	for(std::map<int, Transform>::iterator iter=poses.begin(); iter!=poses.end();)
	{
		if(signatures.at(iter->first).getWeight() < 0)
		{
			poses.erase(iter++);
		}
		else
		{
			++iter;
		}
	}

	for(int n=0; n<iterations; ++n)
	{
		UINFO("Looking for more loop closures, clustering poses... (iteration=%d/%d, radius=%f m angle=%f rad)",
				n+1, iterations, clusterRadius, clusterAngle);

		std::multimap<int, int> clusters = graph::radiusPosesClustering(
				poses,
				clusterRadius,
				clusterAngle);

		UINFO("Looking for more loop closures, clustering poses... found %d clusters.", (int)clusters.size());

		int i=0;
		std::set<int> addedLinks;
		for(std::multimap<int, int>::iterator iter=clusters.begin(); iter!= clusters.end(); ++iter, ++i)
		{
			if(processState && processState->isCanceled())
			{
				return -1;
				break;
			}

			int from = iter->first;
			int to = iter->second;
			if(iter->first < iter->second)
			{
				from = iter->second;
				to = iter->first;
			}

			if(rtabmap::graph::findLink(checkedLoopClosures, from, to) == checkedLoopClosures.end())
			{
				// only add new links and one per cluster per iteration
				if(addedLinks.find(from) == addedLinks.end() &&
				   addedLinks.find(to) == addedLinks.end() &&
				   rtabmap::graph::findLink(links, from, to) == links.end())
				{
					checkedLoopClosures.insert(std::make_pair(from, to));

					UASSERT(signatures.find(from) != signatures.end());
					UASSERT(signatures.find(to) != signatures.end());

					RegistrationInfo info;
					// use signatures instead of IDs because some signatures may not be in WM
					Transform t = _memory->computeTransform(signatures.at(from), signatures.at(to), Transform(), &info);

					if(!t.isNull())
					{
						bool updateConstraints = true;
						if(_optimizationMaxLinearError > 0.0f)
						{
							//optimize the graph to see if the new constraint is globally valid

							int fromId = from;
							int mapId = signatures.at(from).mapId();
							// use first node of the map containing from
							for(std::map<int, Signature>::iterator iter=signatures.begin(); iter!=signatures.end(); ++iter)
							{
								if(iter->second.mapId() == mapId)
								{
									fromId = iter->first;
									break;
								}
							}
							std::multimap<int, Link> linksIn = links;
							linksIn.insert(std::make_pair(from, Link(from, to, Link::kUserClosure, t, info.covariance.inv())));
							const Link * maxLinearLink = 0;
							const Link * maxAngularLink = 0;
							float maxLinearError = 0.0f;
							float maxAngularError = 0.0f;
							std::map<int, Transform> optimizedPoses;
							std::multimap<int, Link> links;
							UASSERT(poses.find(fromId) != poses.end());
							UASSERT_MSG(poses.find(from) != poses.end(), uFormat("id=%d poses=%d links=%d", from, (int)poses.size(), (int)links.size()).c_str());
							UASSERT_MSG(poses.find(to) != poses.end(), uFormat("id=%d poses=%d links=%d", to, (int)poses.size(), (int)links.size()).c_str());
							_graphOptimizer->getConnectedGraph(fromId, poses, linksIn, optimizedPoses, links);
							UASSERT(optimizedPoses.find(fromId) != optimizedPoses.end());
							UASSERT_MSG(optimizedPoses.find(from) != optimizedPoses.end(), uFormat("id=%d poses=%d links=%d", from, (int)optimizedPoses.size(), (int)links.size()).c_str());
							UASSERT_MSG(optimizedPoses.find(to) != optimizedPoses.end(), uFormat("id=%d poses=%d links=%d", to, (int)optimizedPoses.size(), (int)links.size()).c_str());
							UASSERT(graph::findLink(links, from, to) != links.end());
							optimizedPoses = _graphOptimizer->optimize(fromId, optimizedPoses, links);
							std::string msg;
							if(optimizedPoses.size())
							{
								for(std::multimap<int, Link>::iterator iter=links.begin(); iter!=links.end(); ++iter)
								{
									// ignore links with high variance
									if(iter->second.transVariance() <= 1.0 && iter->second.from() != iter->second.to())
									{
										UASSERT(optimizedPoses.find(iter->second.from())!=optimizedPoses.end());
										UASSERT(optimizedPoses.find(iter->second.to())!=optimizedPoses.end());
										Transform t1 = optimizedPoses.at(iter->second.from());
										Transform t2 = optimizedPoses.at(iter->second.to());
										UASSERT(!t1.isNull() && !t2.isNull());
										Transform t = t1.inverse()*t2;
										float linearError = uMax3(
												fabs(iter->second.transform().x() - t.x()),
												fabs(iter->second.transform().y() - t.y()),
												fabs(iter->second.transform().z() - t.z()));
										Eigen::Vector3f vA = t1.toEigen3f().linear()*Eigen::Vector3f(1,0,0);
										Eigen::Vector3f vB = t2.toEigen3f().linear()*Eigen::Vector3f(1,0,0);
										float angularError = pcl::getAngle3D(Eigen::Vector4f(vA[0], vA[1], vA[2], 0), Eigen::Vector4f(vB[0], vB[1], vB[2], 0));
										if(linearError > maxLinearError)
										{
											maxLinearError = linearError;
											maxLinearLink = &iter->second;
										}
										if(angularError > maxAngularError)
										{
											maxAngularError = angularError;
											maxAngularLink = &iter->second;
										}
									}
								}
								if(maxLinearLink)
								{
									UINFO("Max optimization linear error = %f m (link %d->%d)", maxLinearError, maxLinearLink->from(), maxLinearLink->to());
								}
								if(maxAngularLink)
								{
									UINFO("Max optimization angular error = %f deg (link %d->%d)", maxAngularError*180.0f/M_PI, maxAngularLink->from(), maxAngularLink->to());
								}

								if(maxLinearError > _optimizationMaxLinearError)
								{
									msg = uFormat("Rejecting edge %d->%d because "
											  "graph error is too large after optimization (%f m for edge %d->%d, %f deg for edge %d->%d). "
											  "\"%s\" is %f m.",
											  from,
											  to,
											  maxLinearError,
											  maxLinearLink->from(),
											  maxLinearLink->to(),
											  maxAngularError*180.0f/M_PI,
											  maxAngularLink?maxAngularLink->from():0,
											  maxAngularLink?maxAngularLink->to():0,
											  Parameters::kRGBDOptimizeMaxError().c_str(),
											  _optimizationMaxLinearError);
								}
							}
							else
							{
								msg = uFormat("Rejecting edge %d->%d because graph optimization has failed!",
										  from,
										  to);
							}
							if(!msg.empty())
							{
								UWARN("%s", msg.c_str());
								updateConstraints = false;
							}
						}

						if(updateConstraints)
						{
							UINFO("Added new loop closure between %d and %d.", from, to);
							addedLinks.insert(from);
							addedLinks.insert(to);
							cv::Mat inf = info.covariance.inv();
							links.insert(std::make_pair(from, Link(from, to, Link::kUserClosure, t, inf)));
							loopClosuresAdded.push_back(Link(from, to, Link::kUserClosure, t, inf));
							UINFO("Detected loop closure %d->%d! (%d/%d)", from, to, i+1, (int)clusters.size());
						}
					}
				}
			}
		}

		if(processState)
		{
			std::string msg = uFormat("Iteration %d/%d: Detected %d loop closures!", n+1, iterations, (int)addedLinks.size()/2);
			UINFO(msg.c_str());
			if(!processState->callback(msg))
			{
				return -1;
			}
		}
		else
		{
			UINFO("Iteration %d/%d: Detected %d loop closures!", n+1, iterations, (int)addedLinks.size()/2);
		}

		if(addedLinks.size() == 0)
		{
			break;
		}

		if(n+1 < iterations)
		{
			UINFO("Optimizing graph with new links (%d nodes, %d constraints)...",
					(int)poses.size(), (int)links.size());
			int fromId = _optimizeFromGraphEnd?poses.rbegin()->first:poses.begin()->first;
			poses = _graphOptimizer->optimize(fromId, poses, links, 0);
			if(poses.size() == 0)
			{
				UERROR("Optimization failed! Rejecting all loop closures...");
				loopClosuresAdded.clear();
				return -1;
			}
			UINFO("Optimizing graph with new links... done!");
		}
	}
	UINFO("Total added %d loop closures.", (int)loopClosuresAdded.size());

	if(loopClosuresAdded.size())
	{
		for(std::list<Link>::iterator iter=loopClosuresAdded.begin(); iter!=loopClosuresAdded.end(); ++iter)
		{
			_memory->addLink(*iter, true);
		}
	}
	return (int)loopClosuresAdded.size();
}