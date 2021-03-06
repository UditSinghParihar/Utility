#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "matplotlibcpp.h"
#include <Eigen/Dense>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>

#define PI 3.1415

namespace plt = matplotlibcpp;
using namespace std;
using namespace Eigen;

float rad2deg(float theta_radian){
	return (180*theta_radian)/PI;
}

struct Pose{
	float x;
	float y;
	float theta_z;
	int id;
	Pose(float x=0.0, float y=0.0, float theta_z=0.0, int id=0){
		this->x = x;
		this->y = y;
		this->theta_z = theta_z;
		this->id = id;
	};
	
	friend ostream& operator<<(ostream& out, const Pose& pose){
		out << "Id: " << pose.id << "\tx: "<< pose.x << "\ty: " << pose.y
			<< "\ttheta_z(deg): " << rad2deg(pose.theta_z) << "\n--\n";
		return out;
	}
};

struct Edge{
	float delta_x;
	float delta_y;
	float delta_theta;
	int to_id;
	int from_id;
	Edge(float delta_x=0.0, float delta_y=0.0, float delta_theta=0.0,
			int from_id=0, int to_id=0){
		this->delta_x = delta_x;
		this->delta_y = delta_y;
		this->delta_theta = delta_theta;
		this->from_id =from_id;
		this->to_id = to_id;
	};

	friend ostream& operator<<(ostream& out, const Edge& edge){
		out << "from: " << edge.from_id << "\tto: " << edge.to_id 
			<< "\tdelta_x: " << edge.delta_x << "\tdelta_y: " << edge.delta_y
			<< "\tdelta_theta(deg): " << rad2deg(edge.delta_theta) << "\n--\n";
	}	
};

void new_point_in_current_frame(const Edge& edge, const Pose& old_pose, 
								Pose& new_pose){
	new_pose.x = edge.delta_x;
	new_pose.y = edge.delta_y;
	new_pose.theta_z = old_pose.theta_z + edge.delta_theta; 
}

void get_current_frame_in_world_frame(Affine3f& frame, const Pose& pose){
	frame = Affine3f::Identity();
	frame.translation() << pose.x, pose.y, 0;
	frame.rotate(AngleAxisf(pose.theta_z, Vector3f::UnitZ()));
}

void new_point_in_world_frame(const Pose& pose_current, const Affine3f& homogeneous,
								Pose& pose_world){
	const Vector4f old_vector{pose_current.x, pose_current.y, 0, 1};
	Vector4f new_vector;
	new_vector = homogeneous*old_vector;
	pose_world.x = new_vector[0];
	pose_world.y = new_vector[1];
	pose_world.theta_z = pose_current.theta_z;
}

void initial_frame_in_world_frame(Affine3f& homogeneous){
	homogeneous = Affine3f::Identity();
	homogeneous.translation() << 2.0, 2.0, 0;
}

void plot_coordinate_axis(void){
	vector<int> x_points{0, 0, 10};
	vector<int> y_points{10, 0, 0};
	plt::plot(x_points, y_points, "bo-");
}

void plot_graph(const vector<Pose>& poses){
	vector<float> x_points, y_points, thetas;
	for(int i=0; i<poses.size(); ++i){
		x_points.push_back(poses[i].x);
		y_points.push_back(poses[i].y);
		thetas.push_back(poses[i].theta_z);
	}

	const int length = 1;
	plt::plot(x_points, y_points, "ro");
	for(int i=0; i<x_points.size(); ++i){
		vector<float> x_arrow{x_points[i], x_points[i] + length*cos(thetas[i])};
		vector<float> y_arrow{y_points[i], y_points[i] + length*sin(thetas[i])};
		plt::plot(x_arrow, y_arrow, "b->");
	}
	plt::xlim(-2, 30);
	plt::ylim(-2, 30);
	plot_coordinate_axis();
	plt::show();
}

void add_noise(const Edge& correct_edge, Edge& noisy_edge){
	const float range = 0.15;
	const int numbers = range * 200;
	const float noise = (-range) + float(rand()%(numbers))/100;

	noisy_edge.delta_x = noise + correct_edge.delta_x;
	noisy_edge.delta_y = noise + correct_edge.delta_y;
	noisy_edge.delta_theta = noise + correct_edge.delta_theta;
	noisy_edge.from_id = correct_edge.from_id;
	noisy_edge.to_id = correct_edge.to_id;
}

void add_loop_closing_edge(const Pose& first, const Pose& second,
							vector<Edge>& edges){
	Affine3f first_in_world_frame, second_in_world_frame, second_frame_in_first;
	get_current_frame_in_world_frame(first_in_world_frame, first);
	get_current_frame_in_world_frame(second_in_world_frame, second);
	second_frame_in_first = first_in_world_frame.inverse()*second_in_world_frame;
	
	float delta_x = second_frame_in_first.matrix()(0, 3);
	float delta_y = second_frame_in_first.matrix()(1, 3);
	float delta_theta = acos(second_frame_in_first.matrix()(0, 0));
	edges.push_back(Edge(delta_x, delta_y, delta_theta, first.id, second.id));
}

void write_g2o_file(const vector<Pose>& poses, const vector<Edge>& edges,
					const char* file_path){
	ofstream file_write(file_path);
	string vertex_type = "VERTEX_SE2";
	string edge_type = "EDGE_SE2";
	string upper_triangular_info_matrix = "1000.0 0.0 0.0 1000.0 0.0 1000.0";
	for(int i=0; i<poses.size(); ++i){
		file_write << vertex_type << " " << poses[i].id << " "<< poses[i].x << " "
					<< poses[i].y << " " << poses[i].theta_z << endl;
	}

	for(int i=0; i<edges.size(); ++i){
		file_write << edge_type << " " << edges[i].from_id  << " " << edges[i].to_id 
					<< " " << edges[i].delta_x << " " << edges[i].delta_y << " "
					<< edges[i].delta_theta << " " << upper_triangular_info_matrix
					<< endl;
	}

	file_write.close();
}

void print_graph(const vector<Pose>& poses, const vector<Edge>& edges){
	cout << "--Poses--\n";
	for(int i=0; i<poses.size(); ++i){
		cout << poses[i];
	}
	cout << "--Edges--\n";
	for(int i=0; i<edges.size(); ++i){
		cout << edges[i];
	}
}

#endif