#include <iostream>
#include "constants.h"
#include <stdio.h>

using namespace std;
using namespace constants;

int main(int argc, char const *argv[]){
	float var = 3.4f;
	cout << var <<endl ;
	int bin(0);
	bin = 0x0A;
	cout << bin << endl;
	constexpr int classes = 30;
	cout << classes << endl;
	fprintf(stdout, "age: %d \tpi:%g \tgravity:%g\n", AGE, PI, GRAVITY);
	return 0;
}