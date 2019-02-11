#ifndef RECORD_KEYPOINTS_H
#define RECORD_KEYPOINTS_H

#include <iostream>
#include <opencv2/opencv.hpp>

namespace gui{

using namespace std;
using namespace cv;

struct ImageInfo{
	Mat& image;
	vector<Point2f>& keypoints;
	const string& window_name;

	ImageInfo(Mat& arg_image, vector<Point2f>& arg_keypoints,
				const string& window):
				image{arg_image},
				keypoints{arg_keypoints},
				window_name{window}{};
};

class GenerateKeypoints{
private:
	Mat &rgb1;
	vector<Point2f>& keypoints1;

private:
	static void on_mouse1(int event, int x, int y, int flags, void* user_data){
		if(flags == EVENT_FLAG_LBUTTON){
			static int counter1=0;
			ImageInfo& info = *(ImageInfo*) user_data;
			Point2f point(x, y);
			
			circle(info.image, point, 3, Scalar(0, 0, 255), 1, 8, 0);
			imshow(info.window_name, info.image);

			if(counter1%2 == 0){
			cout << "Coordinate of image1: " << x << " " << y << "\n";
				info.keypoints.push_back(point);
			}
			++counter1;
		}
	}
	
	void start_gui(void){
		const string window_name1 = "opencv_viewer1";
	
		namedWindow(window_name1, WINDOW_AUTOSIZE);	
		moveWindow(window_name1, 10, 50);

		ImageInfo info1{rgb1, keypoints1, window_name1};

		setMouseCallback(window_name1, on_mouse1, &info1);

		imshow(window_name1, rgb1);

		waitKey(0);

		destroyWindow(window_name1);
	}

	void print_keypoints(void){
		cout << "Keypoints in image1: " << keypoints1.size() << endl;
		for(auto element : keypoints1){
			cout << element << endl;
		}
	}

public:
	GenerateKeypoints(Mat& arg_rgb1, vector<Point2f>& kps1):
						rgb1{arg_rgb1},
						keypoints1{kps1}{};

	void start_processing(void){
		start_gui();
		print_keypoints();
	}	
};

} // namespace gui

#endif