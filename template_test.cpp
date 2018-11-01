#include "template.h"
#include <string>

using namespace std;

template <typename T>
void print(INTARR<T> &arr, int length){
	for(int i=0; i<length; ++i)
		std::cout << arr[i] << " ";
	std::cout << endl;
}

int main(int argc, char const *argv[]){
	INTARR<int> arr(5);
	for(int i=0; i<5; ++i)
		arr[i] = i*i;
	print(arr, 5);
	INTARR<string> arr_str(5);
	arr_str[0]=" hello ";
	arr_str[1]=" whats ";
	arr_str[2]=" up ";
	arr_str[3]=" hey ";
	arr_str[4]=" yoo ";
	print(arr_str, 5);
	return 0;
}