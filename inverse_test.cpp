#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int a[10];
	for(int i=0; i<10; ++i){
		a[i] = i*i;
	}

	for(int i=0; i<10; ++i){
		fprintf(stdout, "%d is same as %d\n", a[i], i[a]);
	}
	return 0;
}