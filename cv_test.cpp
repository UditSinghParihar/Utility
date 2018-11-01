#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]){
	cv::Mat image = cv::imread(argv[1], cv::IMREAD_COLOR);
	if(! image.data){
		cout << "Fail to load image\n";
		return 1;
	}
	cv::namedWindow("opencv_viewer", cv::WINDOW_AUTOSIZE);
	cv::imshow("opencv_viewer", image);
	cv::waitKey(0);
	return 0;
} 
