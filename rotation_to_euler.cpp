#include <iostream>
#include <Eigen/Geometry>


#define pi 3.14
#define rad2deg(num)(num * 180/pi)

using namespace std;
using namespace Eigen;

void rotation_to_euler(const Eigen::Matrix3f& mat){
	float y_angle = atan2(-mat(2, 0), sqrt(pow(mat(0, 0), 2) + pow(mat(1, 0), 2)));
	float z_angle = atan2(mat(1, 0)/cos(y_angle), mat(0, 0)/cos(y_angle));
	float x_angle = atan2(mat(2, 1)/cos(y_angle), mat(2, 2)/cos(y_angle));

	fprintf(stdout, "Rotation to euler(in degree):\nx_angle: %f\ty_angle: %f\tz_anlge: %f\n",
			rad2deg(x_angle), rad2deg(y_angle), rad2deg(z_angle));
}

void quaternion_to_euler(const Eigen::Matrix3f& rotate){
	Eigen::Quaternionf q(rotate);
	auto euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
	fprintf(stdout, "Quaternion to euler(in degree):\n %g %g %g\n",
			rad2deg(euler[0]), rad2deg(euler[1]), rad2deg(euler[2]) );
}

int main(int argc, char const *argv[]){
	Eigen::Matrix3f rotation;
	rotation <<	-0.978359,   0.192197, -0.0766393,
 -0.199858,  -0.973686,   0.109512,
-0.0535747,   0.122459,   0.991027;

	rotation_to_euler(rotation);
	quaternion_to_euler(rotation);

	return 0;
}
