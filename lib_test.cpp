#include <iostream>
#include "myclass.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[]){
	if(argc == 2){
		test_class obj;
		obj.value = 5;
		double num = atof(argv[1]);
		/*fprintf(stdout, "obj.value: %d\nnumber: %d\nits square root: %d\n", obj.value, num, obj.foo(num));
	*/
		cout << "obj.value: "<< obj.value;
		cout << "\nnumber: " << num;
		cout << "\nits square root: " << obj.foo(num)<<endl;
		return 0;
	}
	else
		cout << "Provide a number\n";
	return 1;
}
