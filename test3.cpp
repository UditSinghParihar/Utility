#include <iostream>
#include <stdio.h>
using namespace std;

class polygon{
protected:
	int width;
	int breath;
public:
	void set_values(int w = 2, int b = 3){
		width = w;
		breath = b;
	}
	virtual double get_area(void){
		return 4444;
	}
};

class rect : public polygon{
public:
	double get_area(void) {
		return width * breath;
	}
	
};

class traingle : public polygon{
public:
	double get_area(void){
		return 0.5 * width * breath;
	}
};

int main(int argc, char const *argv[])
{
	rect obj1;
	traingle obj2;
	polygon obj3;
	polygon *p1 = &obj1;
	polygon *p2 = &obj2;
	polygon *p3 = &obj3;
	p1->set_values(10,20);
	p2->set_values(10,20);
	p3->set_values(10,20);
	fprintf(stdout, "rectangle area: %g \ntriangle area: %g \npolygon area: %g \n", p1->get_area(), p2->get_area(), p3->get_area());
	return 0;
}