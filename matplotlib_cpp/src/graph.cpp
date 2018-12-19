#include <iostream>
#include <vector>
#include <cmath>
#include "matplotlibcpp.h"
#include <Eigen/Dense>

namespace plt = matplotlibcpp;
using namespace std;

#define PI 3.1415

float deg2rad(float theta_degree){
	return (PI*theta_degree)/180;
}

void plot_graph(vector<float>& x_points, vector<float>& y_points, vector<float>& thetas){
	const int length = 1;
	plt::plot(x_points, y_points, "ro-");
	for(int i=0; i<x_points.size(); ++i){
		vector<float> x_arrow{x_points[i], x_points[i] + length*cos(deg2rad(thetas[i]))};
		vector<float> y_arrow{y_points[i], y_points[i] + length*sin(deg2rad(thetas[i]))};
		plt::plot(x_arrow, y_arrow);
	}
	plt::show();
}

void get_translation_matrix(Eigen::Affine3f& translate){
	translate = Eigen::Affine3f::Identity();
	translate.translation() << 2.0, 0, 0;
}

void get_rotation_matrix(Eigen::Affine3f& translate){
	translate.rotate(Eigen::AngleAxisf(PI/12, Eigen::Vector3f::UnitX()));
}

void get_synthetic_poses(vector<float>& x_points, vector<float>& y_points, vector<float>& thetas){
	x_points = vector<float>{1, 2, 3, 4};
	y_points = vector<float>{3, 9, 15, 1};
	thetas = vector<float>{20, 90, 45, 60};
}

int main(int argc, char const *argv[]){
	vector<float> x_points, y_points, thetas;
	get_synthetic_poses(x_points, y_points, thetas);
	plot_graph(x_points, y_points, thetas);

	return 0;
}