#include <iostream>
#include "container.h"

using namespace std;

int main(int argc, char const *argv[]){
	intarray arr(5);
	for(int i = 0; i< 5; i++)
		arr[i] = i*i;
	for(int i =0; i<5; i++)
		cout << arr[i] << "\t";
	cout << endl << arr.get_size() << endl;
	/*arr.erase();
	cout << arr.get_size() << endl;
	arr.reallocate(3);
	cout << arr.get_size() << endl;*/
	arr.insert_before(3, 14);
	for(int i =0; i<6; i++)
		cout << arr[i] << "\t";
	cout << endl;
	return 0;
}