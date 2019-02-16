#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point{
private:
	int m_x;
	int m_y;

public:
	Point(int x=0, int y=0): m_x{x}, m_y{y}{};
	
	friend ostream& operator<<(ostream& out, const Point& point){
		out << "Coordinates are (" << point.m_x << ", " << point.m_y << ")\n";
		return out;
	}
};

#endif