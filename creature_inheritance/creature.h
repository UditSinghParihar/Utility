#include <iostream>
#include <string>

#include "point.h"

using namespace std;

class Creature{
private:
	string m_name;
	Point m_point;

public:
	Creature(const string& name, const Point& point): m_name{name}, m_point{point}{};
	
	friend ostream& operator<<(ostream& out, const Creature& creature){
		out << creature.m_name << " is at: " << creature.m_point << endl;
		return out;
	}
};