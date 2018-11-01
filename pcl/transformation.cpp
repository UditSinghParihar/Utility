#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <stdio.h>

using namespace std;
using namespace pcl;

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
	PointCloud<PointXYZ>::Ptr source (new PointCloud<PointXYZ>);
	PointCloud<PointXYZ>::Ptr target (new PointCloud<PointXYZ>);
	if(io::loadPCDFile<PointXYZ> (argv[1], *source) == 0 && io::loadPCDFile<PointXYZ> (argv[2], *target) == 0)
		cout << "Both files successfully loaded\n";
	else{
		cout << "Give path to pcd files!! \n";
		return 1;
	}

	IterativeClosestPoint<PointXYZ, PointXYZ> icp;
	icp.setInputSource(source);
	icp.setInputTarget(target);
	//icp.setMaximumIterations (50);
	//icp.setTransformationEpsilon (1e-8);

	PointCloud<PointXYZ> transformed; 
	icp.setRANSACIterations(50);
	icp.align(transformed);	
		
	cout << "Has converged: " << icp.hasConverged() << endl << "Score: " << icp.getFitnessScore() << endl;
	Eigen::Matrix4f homogeneous = icp.getFinalTransformation();
	cout << "Final transformation homogeneous Matrix: \n" << homogeneous << endl; 	
	
	homogeneous_to_quaternion(homogeneous);
	return 0;
}