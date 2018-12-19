#include <iostream>
#include <matplotlibcpp.h>
#include <Eigen/Dense>

namespace plt = matplotlibcpp;
using namespace std;
using namespace Eigen;

#define PI 3.1415

void get_forward_translation_matrix(Eigen::Affine3f& translate){
	translate = Eigen::Affine3f::Identity();
	translate.translation() << 2.0, 0, 0;
}

void get_backward_translation_matrix(Eigen::Affine3f& translate){
	translate = Eigen::Affine3f::Identity();
	translate.translation() << -2.0, 0, 0;	
}

void get_rotation_matrix(Eigen::Affine3f& translate){
	translate = Eigen::Affine3f::Identity();	
	translate.rotate(Eigen::AngleAxisf(PI/30, Eigen::Vector3f::UnitZ()));
	cout << "Rotation matrix is:\n" << translate.matrix() << endl;
}

void get_new_pose(const Eigen::Vector4f& old_pose, const Eigen::Affine3f& homogeneous,
					Eigen::Vector4f& new_pose){
	new_pose = homogeneous*old_pose;
}

void get_initial_pose(Eigen::Vector4f& initial_pose){
	initial_pose = Eigen::Vector4f{5, 5 ,0, 1};
}

void plot_coordinate_axis(void){
	vector<int> x_points{0, 0, 10};
	vector<int> y_points{10, 0, 0};
	plt::plot(x_points, y_points, "bo-");
}

void plot_graph(const vector<float>& x_coord, const vector<float>& y_coord){
	plt::plot(x_coord, y_coord, "ro-");
	plt::xlim(0, 30);
	plt::ylim(0, 30);
	plot_coordinate_axis();
	plt::show();
}

void forward_trajectory(vector<float>& x_coord, vector<float>& y_coord, 
						const Eigen::Affine3f& translate){
	Vector4f new_pose;
	get_initial_pose(new_pose);
	x_coord.push_back(new_pose[0]);
	y_coord.push_back(new_pose[1]);
		const int total_points = 10;
	for(int i=0; i<total_points; ++i){
		get_new_pose(new_pose, translate, new_pose);
		
		x_coord.push_back(new_pose[0]);
		y_coord.push_back(new_pose[1]);
	}
}

void left_trajectory(vector<float>& x_coord, vector<float>& y_coord, 
						const Eigen::Affine3f& rotate){
	Vector4f new_pose = Vector4f(x_coord.back(), y_coord.back(), 0, 1);
		const int total_points = 5;
	for(int i=0; i<total_points; ++i){
		get_new_pose(new_pose, rotate, new_pose);
		cout << new_pose << "\n--\n";
		x_coord.push_back(new_pose[0]);
		y_coord.push_back(new_pose[1]);
	}	
}

void backward_trajectory(vector<float>& x_coord, vector<float>& y_coord,
							const Eigen::Affine3f& translate){
	Vector4f new_pose = Vector4f(x_coord.back(), y_coord.back(), 0, 1);
	const int total_points = 5;
	for(int i=0; i<total_points; ++i){
		get_new_pose(new_pose, translate, new_pose);
		x_coord.push_back(new_pose[0]);
		y_coord.push_back(new_pose[1]);
	}	
}

int main(int argc, char const *argv[]){
	Eigen::Affine3f forward_translate, rotate, backward_translate;
	
	get_forward_translation_matrix(forward_translate);
	get_rotation_matrix(rotate);
	get_backward_translation_matrix(backward_translate);

	vector<float> x_coord, y_coord;
	
	forward_trajectory(x_coord, y_coord, forward_translate);
	left_trajectory(x_coord, y_coord, rotate);
	backward_trajectory(x_coord, y_coord, backward_translate);
	
	plot_graph(x_coord, y_coord);
	return 0;
}