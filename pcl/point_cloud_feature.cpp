#include <iostream>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/features/fpfh_omp.h>
#include <cstdio>

using namespace std;
using namespace pcl;

typedef PointNormal PointT;
typedef PointCloud<PointT> PointCloudT;

int main(int argc, char const *argv[]){
	if(argc != 2){
		fprintf(stdout, "Usage: %s cloud1.pcd\n", argv[0]);
		return 1;
	}

	PointCloudT::Ptr cloud(new PointCloudT());
	if(io::loadPCDFile<PointT> (argv[1], *cloud) == -1){
		PCL_ERROR("Couldn't read file \n");
		return -1;
	}

	FPFHEstimationOMP<PointT, PointT, FPFHSignature33> fest;
	const float radius = 5;
	PointCloud<FPFHSignature33>::Ptr cloud_features(new PointCloud<FPFHSignature33>());
	fest.setRadiusSearch(radius);
	fest.setInputCloud(cloud);
	fest.setInputNormals(cloud);
	fest.compute(*cloud_features);
	
	FILE* fid = fopen("features.bin", "wb");
	int nV = cloud->size(), nDim = 33;
	fwrite(&nV, sizeof(int), 1, fid);
	fwrite(&nDim, sizeof(int), 1, fid);
	for (int v = 0; v < nV; v++) {
	    const PointT &pt = cloud->points[v];
	    float xyz[3] = {pt.x, pt.y, pt.z};
	    fwrite(xyz, sizeof(float), 3, fid);
	    const pcl::FPFHSignature33 &feature = cloud_features->points[v];
	    fwrite(feature.histogram, sizeof(float), 33, fid);
	}
	fclose(fid);

	return 0;
}