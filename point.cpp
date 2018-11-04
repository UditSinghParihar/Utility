#include <iostream>
#include <cmath>

using namespace std;

class Point2d{
private:
	double m_x;
	double m_y;
public:
	Point2d(double x=0.0, double y=0.0):m_x{x}, m_y{y}{};
	void print(void){
		fprintf(stdout, "Point2d(%g, %g);\n", m_x, m_y);
	}
	double distanceTo(const Point2d& obj)const{
		return sqrt(pow(m_x-obj.m_x, 2) + pow(m_y-obj.m_y, 2));
	}
	friend double distanceFrom(const Point2d& obj1, const Point2d& obj2);
};

double distanceFrom(const Point2d& obj1, const Point2d& obj2){
	return sqrt(pow(obj1.m_x-obj2.m_x, 2) + pow(obj1.m_y-obj2.m_y, 2));
}

int main(int argc, char const *argv[]){
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();
	cout << "Distance between two points: "<< first.distanceTo(second) << endl;
	cout << "Distance between function: " << distanceFrom(first, second) << endl;
	return 0;
}