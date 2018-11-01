#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;
using namespace pcl;

int main(int argc, char const *argv[]){
	PointCloud<PointXYZ>::Ptr cloud (new PointCloud<PointXYZ>);
	if(io::loadPCDFile<PointXYZ> ("/home/udit/scans/cloud15.pcd", *cloud) == -1){
		PCL_ERROR("Couldn't read file \n");
		return -1;
	}
	cout << "Number of points: " << cloud->width * cloud->height << endl;

	visualization::PCLVisualizer viewer("Visualizing point cloud");
	visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_handler (cloud, 255, 20, 20);
	viewer.addPointCloud(cloud, color_handler,"visual_cloud");
	viewer.addCoordinateSystem (1.0, "cloud", 0);
  	viewer.setBackgroundColor(0.05, 0.05, 0.05, 0); // Setting background to a dark grey
 	viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "visual_cloud");

 	while(! viewer.wasStopped())
 		viewer.spinOnce();
	return 0;
}
