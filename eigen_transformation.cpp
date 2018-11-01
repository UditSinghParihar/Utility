#include<iostream>
#include<Eigen/Geometry>

#define pi 3.14
#define deg2rad2(num)(num * pi / 180)
#define rad2deg(num)(num * 180/pi)

using namespace std;
using namespace Eigen;

float deg2rad(float const num){
	return num * pi / 180;
}

int main(int argc, char const *argv[]){
	char choice{};
	cout << "Do you want to convert Quaternion to euler(q) or Euler to Quaternion(e)\n";
	cin >> choice;
	if(choice=='e'){
		vector<float> v;
		cout << "Enter 3 rpy in degree:\n";
		for (int i = 0; i < 3; ++i){
			float num{};
			cin >> num;
			v.push_back(num);
		}
		Quaternionf q = AngleAxisf(deg2rad2(v[0]), Vector3f::UnitX())
	    * AngleAxisf(deg2rad2(v[1]), Vector3f::UnitY())
	    * AngleAxisf(deg2rad2(v[2]), Vector3f::UnitZ());
	    cout << "euler to Quaternion: \n" << q.coeffs() << endl;		
		auto euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
		fprintf(stdout, "Quaternion to euler in degree: %g %g %g\n",rad2deg(euler[0]), rad2deg(euler[1]), rad2deg(euler[2]) );
	}
	else{
		vector<float> v;
		cout << "Enter 4 Quaternion:\n";
		for (int i = 0; i < 4; ++i){
			float num{};
			cin >> num;
			v.push_back(num);
		}
		Quaternionf q(v[3],v[0],v[1],v[2]);
		cout << "Quaternion is: " << q.coeffs() << endl;
		auto euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
		fprintf(stdout, "Quaternion to euler in degree: %g %g %g\n",rad2deg(euler[0]), rad2deg(euler[1]), rad2deg(euler[2]) );
	}
	return 0;
}