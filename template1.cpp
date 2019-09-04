#include <iostream>

template <typename T>
const T& max(const T& a, const T& b){return a>b ? a : b;}

int main(int argc, char const *argv[]){
	int a = 5, b = 23;
	int c = max(a, b);
	c = 14;
	fprintf(stderr, "a: %d, b: %d, c: %d\n", a, b, c);
	return 0;
}