#include <iostream>

using namespace std;

int add(int a, int b){return a+b;}

int sub(int a, int b){return a-b;}

int mul(int a, int b){return a*b;}

int main(int argc, char const *argv[]){
	if(argc != 4){
		fprintf(stdout, "Usage: %s num1 num2 0/1/2\n0->add\n1->sub\n2->mul\n", argv[0]);
		return 1;
	}

	int a = stoi(argv[1]), b = stoi(argv[2]), op = stoi(argv[3]);
	
	int (*pfcn)(int, int) = nullptr;
	switch(op){
		case 0 : pfcn = add; break;
		case 1 : pfcn = sub; break;
		case 2 : pfcn = mul; break;
	}

	fprintf(stdout, "Result of operation on %d and %d is %d\n", a, b, pfcn(a,b));
	return 0;
}