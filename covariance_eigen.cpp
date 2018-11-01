#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(int argc, char const *argv[])
{
	MatrixXd mat(5, 3);
	mat << 
	90, 80, 40,
	90, 60, 80,
	60, 50, 70,
	30, 40, 70,
	30, 20, 90;
	MatrixXd ones(5, 5);
	ones << 
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1;
	auto alpha = mat - ones * mat * 0.2;
	cout << alpha.transpose()*alpha << endl;
	return 0;
}