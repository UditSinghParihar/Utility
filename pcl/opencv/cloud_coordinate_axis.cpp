#include <iostream>
#include <opencv2/opencv.hpp>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

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

void images2cloud(PointCloudT::Ptr cloud, const Mat& rgb_image, const Mat& depth_image){
	const float f = 570.3, cx = 320.0, cy = 240.0;
	cloud->is_dense = false;
	float bad_point = std::numeric_limits<float>::quiet_NaN();
	int image_index = 0;
	int bad_image_index = 0;

	for(int y=0; y<rgb_image.rows; ++y){
		for(int x=0; x<rgb_image.cols; ++x){
			pcl::PointXYZRGB point;
			if(depth_image.at<unsigned short>(y, x) == 0){
				++bad_image_index;
			}
			else{
				point.z = depth_image.at<unsigned short>(y, x)/1000.0;
				point.x = (x - cx) * point.z / f;
				point.y = (y - cy) * point.z / f;
				
				float temp_z = point.z; 
				float temp_x = point.x;
				float temp_y = point.y;
				point.x = temp_z;
				point.z = -temp_y;
				point.y = -temp_x;

				point.r = rgb_image.at<cv::Vec3b>(y, x)[2];
				point.g = rgb_image.at<cv::Vec3b>(y, x)[1];
				point.b = rgb_image.at<cv::Vec3b>(y, x)[0];
				++image_index;
				cloud->points.push_back(point);
			}
		}
	}
	cloud->width = cloud->points.size();
	cloud->height = 1;
}

void simple_visualize(PointCloudT::Ptr cloud){
	pcl::visualization::PCLVisualizer viewer("pcl_visualizer");
	viewer.addCoordinateSystem(1.0);
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud);
	viewer.addPointCloud(cloud, rgb, "cloud");
	while(! viewer.wasStopped())
		viewer.spinOnce();
}

int main(int argc, char const *argv[]){
	if(argc != 5){
		fprintf(stdout, "Usage: ./cloud_coordinate_axis rgb1.png rgb2.png depth1.png depth2.png\n");
		return 1;
	}
	Mat rgb1 = imread(argv[1], IMREAD_COLOR );
	Mat rgb2 = imread(argv[2], IMREAD_COLOR );
	Mat depth1 = imread(argv[3], IMREAD_ANYDEPTH);
	Mat depth2 = imread(argv[4], IMREAD_ANYDEPTH);
	if(rgb1.empty() || rgb2.empty()){
		fprintf(stdout, "Unable to open images\n");
		return 1;
	}
	// display_image(rgb1);
	PointCloudT::Ptr cloud1(new PointCloudT);
	PointCloudT::Ptr cloud2(new PointCloudT);
	images2cloud(cloud1, rgb1, depth1);
	images2cloud(cloud2, rgb2, depth2);
	simple_visualize(cloud1);
	// simple_visualize(cloud2);
	return 0;
}