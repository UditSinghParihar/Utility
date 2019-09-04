#include <iostream>

using namespace std;

class Base{
public:
	virtual void f1(void){cout << "Inside Base\n";}
};

class Derived : public Base{
public:
	virtual void f1(void){cout << "Inside Derived::f1()\n";}
	
	virtual void f2(void){cout << "Inside Derived::f2()\n";}

	void f3(void){cout << "Inside Derived::f3()\n";}
};

int main(int argc, char const *argv[]){
	Derived d;
	Base *bptr = &d;
	bptr->f1();
	// bptr->f2();
	// bptr->f3();
	
	return 0;
}