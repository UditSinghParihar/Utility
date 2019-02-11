#include <iostream>
#include <opencv2/opencv.hpp>
#include <opevcv2/rgbd.hpp>

using namespace std;
using namespace cv;

void display_image(const Mat& image){
	namedWindow("opencv_viewer", WINDOW_AUTOSIZE);
	imshow("opencv_viewer", image);
	waitKey(0);
	destroyWindow("opencv_viewer");
}

int main(int argc, char const *argv[]){
	if(argc != 3){
		fprintf(stdout, "Usage: %s rgb.png depth.png\n", argv[0]);
		return 1;
	}

	Mat rgb = imread(argv[1], IMREAD_COLOR );
	Mat depth = imread(argv[2], IMREAD_ANYDEPTH);
	
	display_image(rgb);

	if(rgb.empty()){
		fprintf(stdout, "Unable to open images\n");
		return 1;
	}

	const float f = 570.3, cx = 320.0, cy = 240.0;	
	Mat K = (Mat_<double>(3,3) << f, 0, cx, 0, f, cy, 0, 0, 1);
	vector<cv::Point3f> output_cloud;

	cv::rgbd::depthTo3d(depth, K, output_cloud);

	return 0;
}