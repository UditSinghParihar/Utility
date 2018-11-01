#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char const *argv[]){
	Matrix3f mat;
	mat << 0.997138,   0.0710451,  -0.0258906,    
		  -0.0711013,    0.997469, -0.00123274,    
  		   0.0257366 , 0.00307012,    0.999664; 
  	Quaternionf q(mat);
	cout << mat << endl;
	cout << "Quaternion: " << q.coeffs() << endl;
	auto euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
	cout << "\nQuaternion to euler(in rad): \n" << euler << endl;
	cout << mat(0,1);

	return 0;
}
