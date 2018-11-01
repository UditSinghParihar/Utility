#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <Eigen/Dense>
#include <Eigen/Geometry>


using namespace std;
using namespace pcl;

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

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
	if(io::loadPCDFile<PointT> (argv[1], *source) == 0 && io::loadPCDFile<PointT> (argv[2], *target) == 0)
		cout << "Both files successfully loaded\n";
	else{
		cout << "Give path to pcd files!! \n";
		return 1;
	}

	cout << "Before adding, points in source: " << source->width << "\t" << source->height << endl;
	IterativeClosestPoint<PointT, PointT> icp;
	icp.setInputSource(source);
	icp.setInputTarget(target);
	PointCloudT transformed;
	icp.align(transformed);
	cout << "Has converged: " << icp.hasConverged() << endl << "Score: " << icp.getFitnessScore() << endl;
	Eigen::Matrix4f homogeneous = icp.getFinalTransformation();
	homogeneous_to_quaternion(homogeneous);

	pcl::transformPointCloud(*target, *target, homogeneous.inverse());
	*source += *target;
	cout << "After adding, points in source: " << source->width << "\t" << source->height << endl;

	pcl::visualization::PCLVisualizer viewer("Colored Point cloud");
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(source);
	viewer.addPointCloud<PointT>(source, rgb, "source_cloud");

	while(! viewer.wasStopped())
		viewer.spinOnce();
	return 0;
}