#include <iostream>
#include <vector>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>


using namespace std;
using namespace pcl;

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

void simple_visualize(const PointCloudT::Ptr cloud){
	pcl::visualization::PCLVisualizer viewer("Reddening");
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud);
	viewer.addPointCloud<PointT>(cloud, rgb, "cloud_points");
	while(! viewer.wasStopped())
		viewer.spinOnce();
}

void simple_voxelize(const PointCloudT::Ptr cloud){
	pcl::VoxelGrid<PointT> voxel;
	voxel.setInputCloud(cloud);
	voxel.setLeafSize(0.1f, 0.1f, 0.1f);
	voxel.filter(*cloud);
}

void red_colorization(PointCloudT::Ptr cloud){
	vector<PointT> points = cloud->points;
}

int main(int argc, char const *argv[]){
	if(argc !=2){
		cout << "Usage: ./colorize file.pcd\n";
		return 1;
	}
	PointCloudT::Ptr cloud(new PointCloudT);
	io::loadPCDFile<PointT> (argv[1], *cloud);
	cout << "Before reddening.\n";
	simple_visualize(cloud);
	
	simple_voxelize(cloud);
	red_colorization(cloud);	
	return 0;
}