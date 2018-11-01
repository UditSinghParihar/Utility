#include <iostream>
#include <stdio.h>
using namespace std;

void foo(char *ptr, int size){
	cout << "Inside foo!!\n";
	for(int i = 0; i < size; i++)
		cout << *(ptr + i);
	cout << endl;
}

int main(){ 
    char str[] = "hello usp, whats going on!";
    fprintf(stdout, "%p\n%p\n", str + 1, &str + 1);
	foo(str, sizeof(str));
    	return 0; 
} 
