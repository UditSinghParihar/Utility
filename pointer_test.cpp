#include <iostream>
#include <stdio.h>
#include <typeinfo>

using namespace std;

void foo(char *ptr, int size){
	cout << "Inside foo!!\n";
	for(int i = 0; i < size; i++)
		cout << *(ptr + i);
	cout << endl;
}

void print_size(int *ptr){
	cout << sizeof(ptr) << endl;
}

int main(){ 
 //    char str[] = "hello usp, whats going on!";
 //    fprintf(stdout, "%p\n%p\n", str + 1, &str + 1);
	// foo(str, sizeof(str));
    
    // int num=5;
    // int *ptr = &num;
    // fprintf(stdout, "value of num: %d.\n", *ptr);
    // cout << "Type of ptr: "<< typeid(num).name() << endl;

    int array[5]{1,2,3,4,5};
    int *ptr2 = array;
    // cout << "Address of pointer: " << &ptr2 << endl << &array[0] << endl;
    print_size(array);
    
    return 0; 
} 
