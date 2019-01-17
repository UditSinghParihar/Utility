#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/registration/icp.h>
#include <pcl/registration/registration.h>
#include <Eigen/Dense>

#define PI 3.1415

using namespace std;
using namespace pcl;

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

void simple_visualize(const PointCloudT::Ptr cloud1, const PointCloudT::Ptr cloud2, const pcl::Correspondences& correspond={}){
	pcl::visualization::PCLVisualizer viewer("ICP");
	viewer.addCorrespondences<PointT>(cloud1, cloud2, correspond);
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb1(cloud1);
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb2(cloud2);
	viewer.addPointCloud(cloud1, rgb1, "cloud1");
	viewer.addPointCloud(cloud2, rgb2, "cloud2");
	viewer.setBackgroundColor(255, 255, 255, 0);
	while(! viewer.wasStopped())
		viewer.spinOnce();
}

void simple_visualize(const PointCloud<PointXYZ>::Ptr cloud1, const PointCloud<PointXYZ>::Ptr cloud2,const pcl::Correspondences& correspond={}){
	pcl::visualization::PCLVisualizer viewer2("Custom cloud");
	viewer2.addCorrespondences<PointXYZ>(cloud1, cloud2, correspond);
	
	viewer2.setShapeRenderingProperties(
		pcl::visualization::RenderingProperties::PCL_VISUALIZER_LINE_WIDTH,
		3, "correspondences");
	viewer2.setShapeRenderingProperties(
		pcl::visualization::RenderingProperties::PCL_VISUALIZER_COLOR,
		0, 0, 220, "correspondences");

	pcl::visualization::PointCloudColorHandlerCustom<PointXYZ> red_handle(cloud1, 230, 20, 20);
	pcl::visualization::PointCloudColorHandlerCustom<PointXYZ> red_handle2(cloud2, 230, 20, 20);
	viewer2.addPointCloud(cloud1, red_handle, "cloud1");
	viewer2.addPointCloud(cloud2, red_handle2, "cloud2");
	viewer2.setPointCloudRenderingProperties(visualization::PCL_VISUALIZER_POINT_SIZE, 5, "cloud1");
	viewer2.setPointCloudRenderingProperties(visualization::PCL_VISUALIZER_POINT_SIZE, 5, "cloud2");
	viewer2.addCoordinateSystem();
	viewer2.setBackgroundColor(255, 255, 255, 0);
	while(!viewer2.wasStopped())
		viewer2.spinOnce();
}

template <typename CloudTypePtr, typename CloudType, typename PointType>
Eigen::Matrix4f simple_icp(CloudTypePtr source, CloudTypePtr target, pcl::Correspondences& out_correspondences={}){
	Eigen::Matrix4f homogeneous;
	if(out_correspondences.size() == 0){
		cout << "Doing align\n";
		IterativeClosestPoint<PointType, PointType> icp;
		icp.setInputSource(source);
		icp.setInputTarget(target);
		CloudType transformed;
		icp.align(transformed);
		homogeneous = icp.getFinalTransformation();
		out_correspondences = (*icp.correspondences_);
		fprintf(stdout, "Has converged?: %d\t Score: %g\n", icp.hasConverged(), icp.getFitnessScore());
	}
	else{
		cout << "Doing estimateRigidTransformation\n";
		pcl::registration::TransformationEstimationSVD<PointType, PointType> transform_estimation;
		transform_estimation.estimateRigidTransformation(*source, *target, out_correspondences, homogeneous);
	}
	transformPointCloud(*target, *target, homogeneous.inverse());
	// for(size_t i=0; i<out_correspondences.size(); ++i){
	// 	cout << out_correspondences[i] << endl;
	// }
	return homogeneous;
}

void cloud_create(PointCloud<PointXYZ>::Ptr cloud,const int num_points){
	cloud->width = num_points;
	cloud->height = 1;
	cloud->is_dense = true;
	cloud->points.resize(cloud->width * cloud->height);
	float dy1=0.0, dy2=0.5, dx=0.0;
	for(size_t i=0; i<cloud->points.size(); ++i){
		if(i < 9){
			cloud->points[i].x = 1;
			cloud->points[i].y = 1 + dy1;
			cloud->points[i].z = 0;
			dy1 += 0.5;
		}
		else if(i>=9 && i<20){
			cloud->points[i].x = 1 + dx;
			cloud->points[i].y = 5.5;
			cloud->points[i].z = 0;
			dx += 0.5;
		}
		else{
			cloud->points[i].x = 6.5;
			cloud->points[i].y = 6 - dy2;
			cloud->points[i].z = 0;
			dy2 += 0.5;
		}
	}
}

void shift_cloud(const PointCloud<PointXYZ>::Ptr source_cloud, const PointCloud<PointXYZ>::Ptr transformed_cloud){
	Eigen::Affine3f transform = Eigen::Affine3f::Identity();
	transform.translation() << 0.0, 0.0, 0.0;
	transform.rotate(Eigen::AngleAxisf (PI, Eigen::Vector3f::UnitZ()));
	transformPointCloud(*source_cloud, *transformed_cloud, transform);
}

void fill_correspondences(pcl::Correspondences& out_correspondences, const int num_points){
	for(int i=0; i<2; ++i){
		out_correspondences.push_back(pcl::Correspondence(i, i, 0.0));
	}

	int last_index = num_points-1;
	for(int i=last_index; i>last_index-1; --i){
		cout << i << endl;
		out_correspondences.push_back(pcl::Correspondence(i, i, 0.0));
	}
}

void real_cloud_icp(char const *argv[]){
	PointCloudT::Ptr source(new PointCloudT);
	PointCloudT::Ptr target(new PointCloudT);
	io::loadPCDFile<PointT> (argv[2], *source);
	io::loadPCDFile<PointT> (argv[3], *target);
	cout << "Files successfully loaded\n";
	pcl::Correspondences icp_correspondences;
	simple_icp<PointCloudT::Ptr, PointCloudT, PointT>(source, target, icp_correspondences);
	simple_visualize(source, target, icp_correspondences);
}

float rad2deg(float radian){
	return radian * 180 / PI;
}

void display_homogeneous_to_quaternion(Eigen::Matrix4f homogeneous){
	Eigen::Matrix3f rotate;
	for(int i = 0; i<3 ; i++)
		for(int j = 0; j<3 ; j++ )
			rotate(i,j) = homogeneous(i,j);
	Eigen::Quaternionf q(rotate);
	
	// cout << "Homogeneous matrix: \n" << homogeneous << endl;
	// cout << "Homogeneous inverse:\n" << homogeneous.inverse() << endl;	
	fprintf(stdout, "\nTranslation \n%f %f %f\n", homogeneous(0,3), homogeneous(1,3), homogeneous(2,3));
	Eigen::Matrix<float, 4, 1> coeffs = q.coeffs();	
	fprintf(stdout, "Quaternion:\n%f %f %f %f\n", coeffs[0], coeffs[1], coeffs[2], coeffs[3]);
	fprintf(stdout, "g2o edge:\n%f %f 0 0 0 %f %f\n", homogeneous(0,3), homogeneous(1,3), coeffs[2], coeffs[3]);
	auto euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
	fprintf(stdout, "Quaternion to euler in degree: %g %g %g\n",rad2deg(euler[0]), rad2deg(euler[1]), rad2deg(euler[2]) );
}

void toy_cloud_icp(char const *argv[]){
	PointCloud<PointXYZ>::Ptr source_cloud(new PointCloud<PointXYZ>());
	PointCloud<PointXYZ>::Ptr transformed_cloud(new PointCloud<PointXYZ>());
	const int num_points = 25;
	cloud_create(source_cloud, num_points);
	shift_cloud(source_cloud, transformed_cloud);
	pcl::Correspondences out_correspondences;
	if(strcmp(argv[1], "-manual")==0){
		fill_correspondences(out_correspondences, num_points);
	}
	simple_visualize(source_cloud, transformed_cloud, out_correspondences);
	Eigen::Matrix4f homogeneous = simple_icp<PointCloud<PointXYZ>::Ptr, PointCloud<PointXYZ>, PointXYZ>
											(source_cloud, transformed_cloud, out_correspondences);
	display_homogeneous_to_quaternion(homogeneous);
	simple_visualize(source_cloud, transformed_cloud, out_correspondences);
}

int main(int argc, char const *argv[]){
	if(argc==2)
		toy_cloud_icp(argv);
	else if(argc==4)
		real_cloud_icp(argv);
	else{
		fprintf(stdout, "Usage ./manual_correspondance -vanila/manual [cloud1.pcd cloud2.pcd]\n");
		return 1;
	}
	return 0;
}
