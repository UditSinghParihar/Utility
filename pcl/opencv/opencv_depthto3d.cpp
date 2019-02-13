#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/rgbd.hpp>

#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>

using namespace std;
using namespace cv;

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

void display_image(const Mat& image){
	namedWindow("opencv_viewer", WINDOW_AUTOSIZE);
	imshow("opencv_viewer", image);
	waitKey(0);
	destroyWindow("opencv_viewer");
}

void point_cloud_from_matrix(PointCloudT::Ptr cloud, const Mat3b& cloud_matrix){
	cout << "Number of rows and cols:\n" << cloud_matrix.rows << "\t" << cloud_matrix.cols << endl;
	for(int y=0; y<cloud_matrix.rows; ++y){
		for(int x=0; x<cloud_matrix.cols; ++x){
			PointT point;
			point.x = cloud_matrix.at<cv::Vec3b>(y, x)[0];
			point.y = cloud_matrix.at<cv::Vec3b>(y, x)[1];
			point.z = cloud_matrix.at<cv::Vec3b>(y, x)[2];
			point.r = 235;
			point.g = 5;
			point.b = 5;
		}
	}
}

void simple_visualize(PointCloudT::Ptr cloud){
	pcl::visualization::PCLVisualizer viewer("pcl_visualizer");
	viewer.addCoordinateSystem(1.0);
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud);
	viewer.addPointCloud(cloud, rgb, "cloud");
	viewer.setBackgroundColor (220, 220, 220);

	while(! viewer.wasStopped())
		viewer.spinOnce();
}

int main(int argc, char const *argv[]){
	if(argc != 3){
		fprintf(stdout, "Usage: %s rgb.png depth.png\n", argv[0]);
		return 1;
	}

	Mat rgb = imread(argv[1], IMREAD_COLOR);
	Mat depth = imread(argv[2], IMREAD_ANYDEPTH);
	
	display_image(rgb);

	if(rgb.empty()){
		fprintf(stdout, "Unable to open images\n");
		return 1;
	}

	const float f = 570.3, cx = 320.0, cy = 240.0;	
	Mat K = (Mat_<double>(3,3) << f, 0, cx, 0, f, cy, 0, 0, 1);
	Mat cloud_matrix;
	
	cv::rgbd::depthTo3d(depth, K, cloud_matrix);
	cout << "some value: " << cloud_matrix.at<cv::Vec3b>(223, 43) << endl;

	PointCloudT::Ptr cloud(new PointCloudT);
	point_cloud_from_matrix(cloud, cloud_matrix);
	simple_visualize(cloud);

	return 0;
}