#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main(int argc, char const *argv[]){
	Eigen::Matrix3f ortho;
	ortho << 0.68567, 0.14807, 0.71269,
			 0.12975, 0.93855, -0.31982,
			 -0.71626, 0.31176, 0.62433;
	cout << ortho*ortho.transpose() << endl;
	return 0;
}