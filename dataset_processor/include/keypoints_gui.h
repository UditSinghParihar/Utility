#ifndef RECORD_KEYPOINTS_H
#define RECORD_KEYPOINTS_H

#include <iostream>
#include <opencv2/opencv.hpp>

namespace gui{

using namespace std;
using namespace cv;

struct ImageInfo{
	Mat& image;
	vector<pair<int, int>>& keypoints;
	const string& window_name;

	ImageInfo(Mat& arg_image, vector<pair<int, int>>& arg_keypoints,
				const string& window):
				image{arg_image},
				keypoints{arg_keypoints},
				window_name{window}{};
};

class GenerateKeypoints{
private:
	Mat &rgb1, &rgb2, &depth1, &depth2;
	vector<pair<int, int>>& keypoints1;
	vector<pair<int, int>>& keypoints2;

private:
	static void on_mouse1(int event, int x, int y, int flags, void* user_data){
		if(flags == EVENT_FLAG_LBUTTON){
			static int counter1=0;
			ImageInfo& info = *(ImageInfo*) user_data;
			Point point(x, y);
			
			circle(info.image, point, 3, Scalar(0, 0, 255), 1, 8, 0);
			imshow(info.window_name, info.image);

			if(counter1%2 == 0){
			cout << "Coordinate of image1: " << x << " " << y << "\n";
				info.keypoints.push_back(make_pair(x, y));
			}
			++counter1;
		}
	}

	static void on_mouse2(int event, int x, int y, int flags, void* user_data){
		if(flags == EVENT_FLAG_LBUTTON){
			static int counter2=0;
			ImageInfo& info = *(ImageInfo*) user_data;
			Point point(x, y);
			
			circle(info.image, point, 3, Scalar(0, 0, 255), 1, 8, 0);
			imshow(info.window_name, info.image);

			if(counter2%2 == 0){
			cout << "Coordinate of image2: " << x << " " << y << "\n";
				info.keypoints.push_back(make_pair(x, y));
			}
			++counter2;
		}
	}
	
	void generate_composite_image(const Mat3b& rgb, const Mat& depth,
									Mat3b& composite){
		int counter = 0;
		for(int y=0; y<rgb.rows; ++y){
			for(int x=0; x<rgb.cols; ++x){
				if(depth.at<unsigned short>(y, x) == 0){
					++counter;
					composite(y, x) = cv::Vec3b(0, 0, 0);
				}
				else{
					composite(y, x) = rgb(y, x);
				}
			}
		}
		cout << "Bad points gui: " << counter << endl;
	}

	void start_gui(void){
		const string window_name1 = "opencv_viewer1";
		const string window_name2 = "opencv_viewer2";
	
		namedWindow(window_name1, WINDOW_AUTOSIZE);
		namedWindow(window_name2, WINDOW_AUTOSIZE);
		moveWindow(window_name1, 10, 50);
		moveWindow(window_name2, 700, 50);
		
		cv::Mat3b composite_image1(rgb1.size());
		cv::Mat3b composite_image2(rgb2.size());
		generate_composite_image(rgb1, depth1, composite_image1);
		generate_composite_image(rgb2, depth2, composite_image2);

		ImageInfo info1{composite_image1, keypoints1, window_name1};
		ImageInfo info2{composite_image2, keypoints2, window_name2};

		setMouseCallback(window_name1, on_mouse1, &info1);
		setMouseCallback(window_name2, on_mouse2, &info2);

		imshow(window_name1, composite_image1);
		imshow(window_name2, composite_image2);

		waitKey(0);

		destroyWindow(window_name1);
		destroyWindow(window_name2);
	}

	void print_keypoints(void){
		cout << "Keypoints in image1: " << keypoints1.size() << endl;
		for(pair<int, int> element : keypoints1){
			cout << element.first << "\t" << element.second << endl;
		}

		cout << "Keypoints in image2: " << keypoints2.size() << endl;
		for(pair<int, int> element : keypoints2){
			cout << element.first << "\t" << element.second << endl;
		}
	}

public:
	GenerateKeypoints(Mat& arg_rgb1, Mat& arg_rgb2, Mat& arg_depth1, Mat& arg_depth2,
						vector<pair<int, int>>& kps1, vector<pair<int, int>>& kps2):
						rgb1{arg_rgb1},
						rgb2{arg_rgb2},
						depth1{arg_depth1},
						depth2{arg_depth2},
						keypoints1{kps1}, keypoints2{kps2}{	};

	void start_processing(void){
		start_gui();
		print_keypoints();
	}	
};

} // namespace gui

#endif