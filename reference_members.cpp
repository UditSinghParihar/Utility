#include <iostream>

using namespace std;

class Foo{
private:
	int &num1, &num2; 
public:
	Foo(int &arg_num1, int &arg_num2):num1{arg_num1}, num2{arg_num2}{};
	void increment_arguments(void){
		++num1;
		++num2;
	}
};

int main(int argc, char const *argv[]){
	int num1=5, num2=15;
	Foo obj(num1, num2);
	obj.increment_arguments();
	fprintf(stdout, "num1: %d \tnum2: %d\n", num1, num2);
	return 0;
}