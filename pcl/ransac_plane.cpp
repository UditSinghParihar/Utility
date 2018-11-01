#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <Eigen/Dense>
#include <pcl/registration/icp.h>

using namespace std;
using namespace pcl;

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

void simple_visualize(const PointCloudT::Ptr cloud){
	pcl::visualization::PCLVisualizer viewer("Planar section");
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud);
	viewer.addPointCloud<PointT>(cloud, rgb, "cloud_points");
	while(! viewer.wasStopped())
		viewer.spinOnce();
}

void simple_ransac(PointCloudT::Ptr cloud, PointCloudT::Ptr output_plane){
	vector<int> inliers;
	SampleConsensusModelPlane<PointT>::Ptr plane(new SampleConsensusModelPlane<PointT> (cloud));
	RandomSampleConsensus<PointT> ransac(plane);
	ransac.setDistanceThreshold(.01);
	ransac.computeModel();
	ransac.getInliers(inliers);
	copyPointCloud<PointT>(*cloud,inliers,*output_plane);
	cout << "Ransac completed\n";	
}

Eigen::Matrix4f simple_icp(PointCloudT::Ptr source, PointCloudT::Ptr target){
	IterativeClosestPoint<PointT, PointT> icp;
	icp.setInputSource(source);
	icp.setInputTarget(target);
	PointCloudT transformed;
	icp.align(transformed);
	cout << "Has converged: " << icp.hasConverged() << endl << "Score: " << icp.getFitnessScore() << endl;
	return icp.getFinalTransformation();
}

void homogeneous_to_quaternion(const Eigen::Matrix4f &homogeneous){
	Eigen::Matrix3f rotate;
	for(int i = 0; i<3 ; i++)
		for(int j = 0; j<3 ; j++ )
			rotate(i,j) = homogeneous(i,j);
	Eigen::Quaternionf q(rotate);
	
	fprintf(stdout, "\nTranslation \n%f %f %f\n", homogeneous(0,3), homogeneous(1,3), homogeneous(2,3));
	Eigen::Matrix<float, 4, 1> coeffs = q.coeffs();	
	fprintf(stdout, "Quaternion:\n%f %f %f %f\n", coeffs[0], coeffs[1], coeffs[2], coeffs[3]);
	fprintf(stdout, "g2o edge:\n%f %f 0 0 0 %f %f\n", homogeneous(0,3), homogeneous(1,3), coeffs[2], coeffs[3]);
}

int main(int argc, char const *argv[]){
	PointCloudT::Ptr source(new PointCloudT);
	PointCloudT::Ptr target(new PointCloudT);
	PointCloudT::Ptr source_plane(new PointCloudT);
	PointCloudT::Ptr target_plane(new PointCloudT);
	if(argc!=3){
		cout << "Usage: ./a.out file1.pcd file2.pcd\n";
		return 1;
	}
	if(io::loadPCDFile<PointT> (argv[1], *source) == 0 && io::loadPCDFile<PointT> (argv[2], *target) == 0){
		cout << "Files successfully loaded\n";
		simple_visualize(source);
		simple_visualize(target);
		cout << "Points in source, before adding: " << source->width << "\t" << source->height << endl;
	}
	simple_ransac(source, source_plane);
	simple_ransac(target, target_plane);
	
	Eigen::Matrix4f homogeneous = simple_icp(source_plane, target_plane);
	transformPointCloud(*target, *target, homogeneous.inverse());
	*source += *target;
	cout << "Points in source, after adding: " << source->width << "\t" << source->height << endl;
	homogeneous_to_quaternion(homogeneous);
	simple_visualize(source);

	return 0;
}