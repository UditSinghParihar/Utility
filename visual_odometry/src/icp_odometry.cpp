#include <iostream>
#include <dirent.h>
#include <string>
#include "graph.h"
#include "sift_icp.h"

using namespace std;

class ParseImages{
private:
	const char* rgb_folder;
	const char* depth_folder;
	vector<string>& rgb_images;
	vector<string>& depth_images;

private:
	int get_cloud_number(const string &str){
		int index = 0;
		string result{};
		while(str[index] != '.'){
			result += str[index];
			++index;
		}
		return stoi(result);
	}

	void get_extension(const string& str, string& extension){
		int index = 0; 
		while(str[index] != '.'){
			++index;
		}
		while(index != str.size()){
			extension += str[index];
			++index;
		}
	}
	
	void get_image_path(int image_index, const string& extension, 
							const char* directory, string& image_path){
		int index=0;
		string path{};
		while(directory[index] != '\0'){
			path += directory[index];
			++index;
		}
		
		image_path = path + to_string(image_index) + extension;
	}

	void parse_images(vector<string>& images, const char* folder){
		string extension;
		bool extension_parsed = false;
		vector<int> list;
		DIR* directory = opendir(folder);
		dirent* pointer;
		while((pointer = readdir(directory)) != NULL){
			if(pointer->d_name[0] != '.'){
				list.push_back(get_cloud_number(pointer->d_name));
				if(extension_parsed == false){
					get_extension(pointer->d_name, extension);
					extension_parsed = true;
				}
			}
		}
		closedir(directory);
		sort(list.begin(), list.end());

		for(int i=0; i<list.size(); ++i){
			string image_path;
			get_image_path(list[i], extension, folder, image_path);
			images.push_back(image_path);
		}
	}

public:
	ParseImages(const char* rgb, const char* depth, vector<string>& rgb_list, 
				vector<string>& depth_list):
				rgb_folder{rgb},
				depth_folder{depth},
				rgb_images{rgb_list},
				depth_images{depth_list}{};

	void start_processing(void){
		parse_images(rgb_images, rgb_folder);
		parse_images(depth_images, depth_folder);
	}
	
};

class GenerateEdges{
private:
	const vector<string>& rgb_images;
	const vector<string>& depth_images;
	Mat rgb1, rgb2, depth1, depth2;

private:
	void load_sequential_images(void){
		rgb1 = imread(rgb_images[1], IMREAD_COLOR );
		rgb2 = imread(rgb_images[2], IMREAD_COLOR );
		depth1 = imread(depth_images[1], IMREAD_ANYDEPTH);
		depth2 = imread(depth_images[2], IMREAD_ANYDEPTH);
	}

	void display_image(const Mat& image){
		namedWindow("opencv_viewer", WINDOW_AUTOSIZE);
		imshow("opencv_viewer", image);
		waitKey(0);
		destroyWindow("opencv_viewer");
	}

public:
	GenerateEdges(const vector<string>& rgb_list, const vector<string>& depth_list):
					rgb_images{rgb_list},
					depth_images{depth_list}{};
	
	void start_processing(void){
		load_sequential_images();
		display_image(rgb1);
	}
};

int main(int argc, char const *argv[]){
	if(argc != 3){
		fprintf(stdout, "Usage: %s /path/to/rgb_images /path/to/depth_images\n",
				argv[0]);
		return 1;
	}

	vector<string> rgb_images;
	vector<string> depth_images;
	ParseImages parser(argv[1], argv[2], rgb_images, depth_images);
	parser.start_processing();

	GenerateEdges generator(rgb_images, depth_images);
	generator.start_processing();

	return 0;
}