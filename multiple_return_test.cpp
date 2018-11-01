#include <iostream>
using namespace std;

class multiple{
public:
	int a;
	int b;
};


class multiple foo(int a, int b){
	multiple obj;
	obj.a = a;
	obj.b = b;
	return obj;
}

double *func(double a, double b){
	double *ptr = new double[3];
	ptr[0] = a*b;
	ptr[1] = a+b;
	ptr[2] = a/b;
	return ptr;
}

int main(int argc, char const *argv[]){
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	auto result = foo(a, b);
	cout << result.a << "\t" << result.b << endl;
	auto ptr = func(a, b);
	fprintf(stdout, "%g\t, %g\t, %g\n", ptr[0], ptr[1], ptr[2]);
	return 0;
}
