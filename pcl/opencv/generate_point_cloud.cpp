#include <iostream>
#include <opencv2/opencv.hpp>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>
#include <cctype>

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
	const float f = 525, cx = 319.5, cy = 239.5;
	cloud->is_dense = false;
	float bad_point = std::numeric_limits<float>::quiet_NaN();
	int image_index = 0;
	int bad_image_index = 0;
	int background_index = 0;
	const int depth_threshold = INT_MAX;
	cv::Vec3b black_pixel{0, 0, 0};

	for(int y=0; y<rgb_image.rows; ++y){
		for(int x=0; x<rgb_image.cols; ++x){
			pcl::PointXYZRGB point;
			if(depth_image.at<float>(y, x) == 0 || 
				depth_image.at<float>(y, x) > depth_threshold){
				++bad_image_index;
			}
			else if(rgb_image.at<cv::Vec3b>(y, x) == black_pixel){
				++background_index;
			}
			else{
				point.z = depth_image.at<float>(y, x)/1000;
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
	fprintf(stdout, "Background black_pixels: %d \n", background_index);
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

void save_to_pcd(string output_path, PointCloudT::Ptr cloud){
	pcl::io::savePCDFileASCII(output_path, *cloud);
	fprintf(stdout, "Point Cloud saved to: %s\n", output_path.c_str());
}

string get_cloud_name(const string& image_name){
	string cloud_name{};
	for(char letter : image_name){
		if(isdigit(letter)){
			cloud_name += letter;	
		}
	}

	cloud_name += ".pcd";
	cout << "cloud_name: " << cloud_name << endl;
	return cloud_name;

}

void read_depth_image(const Mat& depth){
	cout << depth;
}

void apply_mask(Mat& image, const string& side){
	cv::Vec3b black_pixel{0, 0, 0};
	if(side == "left"){
		for(int y=0; y<image.rows; ++y){
        	for(int x=0; x<(image.cols)/2; ++x){
        		image.at<cv::Vec3b>(y, x) = black_pixel;
        	}
        }
        cout << "Left side painted black\n";
	}
	else if(side == "right"){
		for(int y=0; y<image.rows; ++y){
        	for(int x=(image.cols)/2; x<image.cols; ++x){
        		image.at<cv::Vec3b>(y, x) = black_pixel;
        	}
        }
        cout << "Right side painted black\n";
	}
	else if(side == "none"){
		cout << "No mask is applied\n";
	}
}

int main(int argc, char const *argv[]){
	if(argc != 4){
		fprintf(stdout, "Usage: %s rgb.png depth.png masking_side\n", argv[0]);
		return 1;
	}
	
	Mat rgb = imread(argv[1], IMREAD_COLOR );
	Mat depth = imread(argv[2], IMREAD_ANYDEPTH);
	depth.convertTo(depth, CV_32FC1);

	if(rgb.empty()){
		fprintf(stdout, "Unable to open images\n");
		return 1;
	}

	apply_mask(rgb, argv[3]);
	display_image(rgb);

	PointCloudT::Ptr cloud(new PointCloudT);
	images2cloud(cloud, rgb, depth);
	simple_visualize(cloud);

	string final_cloud = get_cloud_name(argv[1]);
	save_to_pcd(final_cloud, cloud);

	// read_depth_image(depth);

	return 0;
}
