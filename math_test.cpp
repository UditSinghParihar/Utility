#include <iostream>
#include <cmath>
#include <string>

#define PI 3.14

double deg2rad(double deg){
	return PI * deg / 180;
}

using namespace std;

int main(int argc, char const *argv[]){
	if(argc != 2){
		cout << "Usage: ./a.out number(in degree)\n";
		return 1;
	}
	double radian = deg2rad(stod(argv[1]));
	fprintf(stdout, "cos(%g) is: %g\t sin(%g) is %g\n", radian, cos(radian), radian, sin(radian));
	int a=2;
	fprintf(stdout, "a^4: %g\nlog10(1000): %g\n", pow(a,4), log10(1000));
	return 0;
}