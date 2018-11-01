#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;
using namespace pcl;

int main(int argc, char const *argv[]){
	if(argc != 2){
		cout << "Provide pcd file!!" << endl;
		return 1;
	}
	PointCloud<PointXYZ>::Ptr cloud (new PointCloud<PointXYZ>);
	if(io::loadPCDFile<PointXYZ> (argv[1], *cloud) == -1){
		PCL_ERROR("Couldn't read file \n");
		return -1;
	}
	else
		cout << "Successfully loaded cloud with "<< cloud->points.size() << " points" << endl;

	pcl::visualization::PCLVisualizer viewer ("visualization example");
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> handle (cloud, 230, 20, 20); // Red
	viewer.addPointCloud (cloud, handle, "red_cloud");

	viewer.addCoordinateSystem (1.0, "cloud", 0);
	viewer.setBackgroundColor(0.05, 0.05, 0.05, 0); // Setting background to a dark grey
	viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "red_cloud");
	

	while (!viewer.wasStopped ()) { // Display the visualiser until 'q' key is pressed
	  viewer.spinOnce ();
	}	
	return 0;
}