#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "file_parser.h"
#include "keypoints_gui.h"
#include "sift_icp.h"
#include "g2o_parser.h"

using namespace std;

void calculate_rt_from_keypoints(const vector<pair<string, string>>& rgb_pairs, 
									const vector<pair<string, string>>& depth_pairs){
	for(int i=0; i<3; ++i){
		vector<pair<int, int>> kps1_coord;
		vector<pair<int, int>> kps2_coord;
		gui::GenerateKeypoints keypoint_gui(rgb_pairs[i].first, rgb_pairs[i].second,
										kps1_coord, kps2_coord);
		keypoint_gui.start_processing();

		Mat rgb1 = imread(rgb_pairs[i].first, IMREAD_COLOR );
		Mat rgb2 = imread(rgb_pairs[i].second, IMREAD_COLOR );
		Mat depth1 = imread(depth_pairs[i].first, IMREAD_ANYDEPTH);
		Mat depth2 = imread(depth_pairs[i].second, IMREAD_ANYDEPTH);

		CloudOperations cloud_processor{rgb1, rgb2, depth1, depth2, kps1_coord, kps2_coord, 1};
		cloud_processor.start_processing();
	}
}

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
	// pair_maker.write_image_pairs();
}

int main(int argc, char const *argv[]){
	if(argc != 5){
		fprintf(stdout, "Usage: %s /path/to/rgb_images /path/to/depth_images trajectories.txt file.g2o\n",
				argv[0]);
		return 1;
	}

	vector<pair<string, string>> rgb_pairs, depth_pairs;
	get_image_pairs(argv[1], argv[2], argv[3], rgb_pairs, depth_pairs);

	// calculate_rt_from_keypoints(rgb_pairs, depth_pairs);

	vector<vector<float>> transforms;
	g2oParser parser(argv[4], transforms);
	return 0;
}