#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <algorithm>
#include <dirent.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/registration/icp.h>

using namespace std;
using namespace Eigen;
using namespace pcl;

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

void simple_visualize(const PointCloudT::Ptr cloud){
	pcl::visualization::PCLVisualizer viewer("Assembled_cloud");
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud);
	viewer.addPointCloud<PointT>(cloud, rgb, "cloud_points");
	while(! viewer.wasStopped())
		viewer.spinOnce();
}

vector<int> find_spaces(const string &line){
	char space = ' ';
	vector<int> index;
	for(int i=0; i<line.length(); ++i){
		if(line[i]==space){
			index.push_back(i);
		}
	}
	return index;
}

vector<double> extract_substring(const string &line, const vector<int> &spaces){
	vector<double> substrings;
	int word_count = 8;
	for(int i=0; i<word_count; ++i){
		string word{};
		for(int j=spaces[i]+1; j<spaces[i+1]; ++j){
			word += line[j];
		}
		substrings.push_back(stod(word));
	}
	return substrings;
}

Eigen::Matrix4d get_homogeneous(const vector<double> &sub){
	Quaterniond q(sub[7], sub[4], sub[5], sub[6]);
	Eigen::Matrix3d rotate = q.toRotationMatrix();
	Eigen::Matrix4d homogeneous = Eigen::Matrix4d::Identity();
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			homogeneous(i, j) = rotate(i, j);
	homogeneous(0, 3) = sub[1];
	homogeneous(1, 3) = sub[2];
	homogeneous(2, 3) = sub[3];
	//cout << "Quaternion:\n" << q.coeffs() << "\nhomogeneous:\n" << homogeneous << endl;
	return homogeneous;
}

int get_cloud_number(const string &str){
	const int cloud_length = 5;
	int index = cloud_length;
	string result{};
	while(str[index] != '.'){
		result += str[index];
		++index;
	}
	return stoi(result);
}

void get_sorted_clouds(vector<string> &clouds,const char *directory){
	int index=0;
	string path{};
	while(directory[index] != '\0'){
		path += directory[index];
		++index;
	}
	vector<int> list;
	string keyword = "cloud";
	DIR* dirp = opendir(directory);
	dirent* dp;
	while((dp = readdir(dirp)) != NULL){
		if(string(dp->d_name).find(keyword) != std::string::npos)
			list.push_back(get_cloud_number(dp->d_name));
	}
	closedir(dirp);
	sort(list.begin(), list.end());
	for(int i=0; i<list.size(); ++i){
		string cloud_name = path + "cloud" + to_string(list[i]) + ".pcd";
		clouds.push_back(cloud_name); 
	}
}

void parse_g2o_file(vector<vector<double>> &poses, const char *g2o_file){
	ifstream file_read(g2o_file);
	string line;
	string keyword = "VERTEX_SE3:QUAT";
	if(file_read.is_open()){
		while(getline(file_read, line)){
			size_t found = line.find(keyword);
			if(found!=string::npos){
				vector<double> cloud_pose = extract_substring(line, find_spaces(line));
				poses.push_back(cloud_pose);
			}
		}
	}
}

int main(int argc, char const *argv[]){
	if(argc != 3){
		cerr << "Usage: ./cloud_assemble file.g2o /path/to/clouds/\n";
		return 1;
	}
	vector<string> sorted_clouds;
	get_sorted_clouds(sorted_clouds, argv[2]);

	vector<vector<double>> poses;
	parse_g2o_file(poses, argv[1]);

	PointCloudT::Ptr start(new PointCloudT);
	if(io::loadPCDFile<PointT> (sorted_clouds[0], *start) == 0){
		cout << "Cloud: " << sorted_clouds[0] << " successfully laoded\n";
	}
	else{
		cout << "Unable to load cloud\n";
		return 1;
	}
	Eigen::Matrix4d first_homogeneous = get_homogeneous(poses[0]);
	transformPointCloud(*start, *start, first_homogeneous.inverse());
	for(int i=1; i<poses.size(); ++i){
		Eigen::Matrix4d homogeneous = get_homogeneous(poses[i]);
	}
	return 0;
}