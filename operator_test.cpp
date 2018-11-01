#include <iostream>
using namespace std;

class complex{
double real;
double comp;
public:
	complex(double a = 0, double b =0){
		real = a;
		comp = b;
	}
	complex operator + (complex const & obj){
		complex res;
		res.real = real + obj.real;
		res.comp = comp + obj.comp;
		return res;
	}
	void print_complex(void){
		cout << "complex number: " <<real << " + i" << comp << endl;
	}
	
};

int main(int argc, char const *argv[]){
	complex obj1(2, 3);
	complex obj2(4, 5);
	complex res;
	res = obj1 + obj2;
	res.print_complex();
	return 0;
}