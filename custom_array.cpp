#include <iostream>
#include "int_array.h"

using namespace std;

int main(int argc, char const *argv[]){
	MYARRAY<float> list1(5), list2{1, 2, 413, 3, 98};
	for(int i=0; i<list1.get_length(); ++i)
		list1[i] = 2.5*i;

	cout << list1 << endl;
	cout << list2 << endl;

	list2 = {1, 34, 100};
	cout << list2 << endl;

	return 0;
}