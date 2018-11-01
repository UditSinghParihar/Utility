#include <iostream>
#include "myclass.h"
#include <math.h>

using namespace std;

double test_class::foo(double a){
	cout << "\nInside foo, calling it from library file: myclass.cpp";
	double answer = sqrt(a);
	return answer;
}