#include "int_array.h"

int main(int argc, char const *argv[]){
	int length = 5;
	int_array<int> arr(length);
	for(int i=0; i<length; ++i){
		arr[i] = i*i;
	}
	std::cout << arr << std::endl << arr.get_length() << std::endl;
	arr.erase();
	std::cout << arr.get_length() << std::endl;
	arr.reallocate(6);
	for(int i=0; i<6; ++i){
		arr[i] = 4*i;
	}
	std::cout << arr << std::endl;
	return 0;
}