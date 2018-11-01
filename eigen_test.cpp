#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <vector>

using namespace std;
using namespace Eigen;

int main(int argc, char const *argv[]){
	vector<float> arr;
	if(argc==5){
		cout << "You entered\n";
		for (int i = 1; i < argc; ++i){
			arr.push_back(stof(argv[i]));
			cout << arr[i-1] << " ";
		}
		Quaternionf q(arr[0],arr[1],arr[2],arr[3]);
		cout << endl << q.toRotationMatrix().eulerAngles(0,1,2) << endl;
	}
	else{
		cout << "Enter 4 Quaternion!!\n";
		return 1;
	}
	return 0;
}