#include <iostream>
#include <Eigen/Geometry>

#define pi 3.14
#define deg2rad2(num)(num * pi / 180)
#define rad2deg(num)(num * 180/pi)

using namespace std;
using namespace Eigen;

float deg2rad(float const num){
	return num * pi / 180;
}

int main(int argc, char const *argv[]){
	Eigen::Matrix3f rotate;
	rotate 	<<	-1,         -0.0440525, -0.0215261,
				-0.0485885,  0.94816,    0.314057, 
				0.00657534, 0.314725,  -0.949161;
	
	Eigen::Quaternionf q(rotate);

	Eigen::Matrix<float, 4, 1> coeffs = q.coeffs();	
	fprintf(stdout, "Quaternion:\n%f %f %f %f\n",
			coeffs[0], coeffs[1], coeffs[2], coeffs[3]);

	auto euler = q.toRotationMatrix().eulerAngles(0,1,2);
	fprintf(stdout, "Euler angles:\n %f %f %f \n",
			rad2deg(euler[0]), rad2deg(euler[1]),rad2deg(euler[2]) );
	
	return 0;
}