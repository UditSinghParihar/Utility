#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>

using namespace std;
using namespace Eigen;

#define pi 3.14
#define rad2deg(num)(num * 180/pi)

void get_transfomation(Quaternionf& q, Vector3f& translate, Matrix4f& transfomation){
	Matrix3f rotation = q.toRotationMatrix();
	transfomation.block<3, 3>(0, 0) = rotation;
	transfomation.block<3, 1>(0, 3) = translate;
}

void rotation_to_euler(const Eigen::Matrix3f& mat){
	float y_angle = atan2(-mat(2, 0), sqrt(pow(mat(0, 0), 2) + pow(mat(1, 0), 2)));
	float z_angle = atan2(mat(1, 0)/cos(y_angle), mat(0, 0)/cos(y_angle));
	float x_angle = atan2(mat(2, 1)/cos(y_angle), mat(2, 2)/cos(y_angle));

	fprintf(stdout, "[%f, %f, %f]\n", rad2deg(x_angle), rad2deg(y_angle), rad2deg(z_angle));
}

void second_in_first(Matrix4f& first, Matrix4f& second){
	Matrix4f edge = first.inverse()*second;
	Matrix3f rotate = edge.block<3, 3>(0, 0);
	rotation_to_euler(rotate);
	
	fprintf(stdout, "[%f, %f, %f]\n", edge(0, 3), edge(1, 3), edge(2, 3));
}

int main(int argc, char const *argv[]){
	if(argc != 15){
		fprintf(stdout, "%s x1 y1 z1 qx1 qy1 qz1 qw1 x2 y2 z2 qx2 qy2 qz2 qw2\n", argv[0]);
		return 1;
	}
	Vector3f translate1(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	Quaternionf q1(atof(argv[7]), atof(argv[4]), atof(argv[5]), atof(argv[6]));
	Vector3f translate2(atof(argv[8]), atof(argv[9]), atof(argv[10]));
	Quaternionf q2(atof(argv[14]), atof(argv[11]), atof(argv[12]), atof(argv[13]));

	Matrix4f transfomation1 = Matrix4f::Identity();
	Matrix4f transfomation2 = Matrix4f::Identity();
	get_transfomation(q1, translate1, transfomation1);
	get_transfomation(q2, translate2, transfomation2);
	
	second_in_first(transfomation1, transfomation2);
	return 0;
}