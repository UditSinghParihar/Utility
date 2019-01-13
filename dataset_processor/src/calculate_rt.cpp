#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "file_parser.h"
#include "g2o_parser.h"
#include "graph.h"
#include "icp.h"

using namespace std;

void get_image_pairs(const char* rgb_folder, const char* depth_folder, const char* file,
						vector<pair<string, string>>& rgb_pairs,
						vector<pair<string, string>>& depth_pairs){
	vector<string> rgb_images;
	vector<string> depth_images;
	ParseImages parser(rgb_folder, depth_folder, rgb_images, depth_images);
	parser.start_processing();
	
	pair<int ,int> going;
	pair<int, int> coming;
	FileParser trajectory_info{file, going, coming};
	trajectory_info.start_processing();

	MatchImagePair pair_maker{rgb_images, depth_images, going, coming, 
								rgb_pairs, depth_pairs};
	pair_maker.start_processing();
}

void show_images(const Mat& rgb1, const Mat& rgb2){
	const string window_name1 = "opencv_viewer1";
	const string window_name2 = "opencv_viewer2";

	namedWindow(window_name1, WINDOW_AUTOSIZE);
	namedWindow(window_name2, WINDOW_AUTOSIZE);
	moveWindow(window_name1, 10, 50);
	moveWindow(window_name2, 700, 50);

	imshow(window_name1, rgb1);
	imshow(window_name2, rgb2);

	waitKey(0);

	destroyWindow(window_name1);
	destroyWindow(window_name2);
}

void icp_refining(const vector<pair<string, string>>& rgb_pairs,
					const vector<pair<string, string>>& depth_pairs, 
					const vector<Edge>& edges){
	
	for(int i=0; i<rgb_pairs.size(); ++i){
		Mat rgb1 = imread(rgb_pairs[i].first, IMREAD_COLOR );
		Mat rgb2 = imread(rgb_pairs[i].second, IMREAD_COLOR );
		Mat depth1 = imread(depth_pairs[i].first, IMREAD_ANYDEPTH);
		Mat depth2 = imread(depth_pairs[i].second, IMREAD_ANYDEPTH);
	
		show_images(rgb1, rgb2);

		CloudOperations cloud_processor{rgb1, rgb2, depth1, depth2, edges[i]};
		cloud_processor.start_processing();
	}
}

int main(int argc, char const *argv[]){
	if(argc != 5){
		fprintf(stdout, "Usage: %s /path/to/rgb_images /path/to/depth_images trajectories.txt file.g2o\n",
				argv[0]);
		return 1;
	}

	vector<pair<string, string>> rgb_pairs, depth_pairs;
	get_image_pairs(argv[1], argv[2], argv[3], rgb_pairs, depth_pairs);

	vector<vector<float>> transforms;
	g2oParser parser(argv[4], transforms);
	parser.start_processing();

	vector<Edge> edges;
	GenerateRT rt_generator{rgb_pairs, depth_pairs, transforms, edges};
	rt_generator.start_processing();

	icp_refining(rgb_pairs, depth_pairs, edges);

	return 0;
}