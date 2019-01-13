#include <iostream>
#include <Eigen/Geometry>
#include <Eigen/Dense>

#define pi 3.14
#define deg2rad(num)(num * pi / 180)
#define rad2deg(num)(num * 180/pi)

using namespace std;
using namespace Eigen;

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

void get_current_frame_in_world_frame(Eigen::Affine3f& frame, const Pose& pose){
	frame = Eigen::Affine3f::Identity();
	frame.translation() << pose.x, pose.y, 0;
	frame.rotate(AngleAxisf(pose.theta_z, Vector3f::UnitZ()));
}

void get_relative_transform(const Pose& first, const Pose& second){
	Eigen::Affine3f first_in_world_frame, second_in_world_frame, second_frame_in_first;
	
	get_current_frame_in_world_frame(first_in_world_frame, first);
	get_current_frame_in_world_frame(second_in_world_frame, second);
	second_frame_in_first = first_in_world_frame.inverse()*second_in_world_frame;
	cout << "second_frame_in_first\n";
	cout << second_frame_in_first.matrix() << endl;

	float delta_x = second_frame_in_first.matrix()(0, 3);
	float delta_y = second_frame_in_first.matrix()(1, 3);
	float delta_theta = acos(second_frame_in_first.matrix()(0, 0));

	Eigen::Vector4f second_pose{7, 5, 0, 1};
	cout << (first_in_world_frame.inverse()).matrix() * second_pose << endl;

}

int main(int argc, char const *argv[]){
	const Pose first{2, 3, deg2rad(0)};
	const Pose second{7, 5, deg2rad(0)};
	
	get_relative_transform(first, second);

	return 0;
}
