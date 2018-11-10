#include <iostream>

using namespace std;

void fun2(int num){
	num += 2;
	return;
}

void fun1(const int& num){
	fun2(num);
}

int main(int argc, char const *argv[]){
	int num =  6;
	fprintf(stdout, "num: %d\n", num);
	return 0;
}