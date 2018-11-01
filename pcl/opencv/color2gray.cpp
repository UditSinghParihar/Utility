#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void display(const Mat& image){
	namedWindow("opencv_viewer", WINDOW_AUTOSIZE);
	imshow("opencv_viewer", image);
	waitKey(0);
}

int main(int argc, char const *argv[]){
	Mat color_image = imread(argv[1], IMREAD_COLOR);
	Mat gray_image;
	cvtColor(color_image, gray_image, COLOR_BGR2GRAY);
	imwrite("gray_image.jpg", gray_image);
	display(color_image);
	display(gray_image);

	Mat red_image(2, 2, CV_32FC3, Scalar(0, 0, 255));
	cout << "red_image = \n" << red_image << endl;
	display(red_image);
	return 0;
}