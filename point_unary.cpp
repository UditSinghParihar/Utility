#include <iostream>

using namespace std;

class Point{
private:
	double m_x, m_y, m_z;

public:
	Point(double x=0.0, double y=0.0, double z=0.0): m_x{x}, m_y{y}, m_z{z}{};
	Point operator-()const;		
	bool operator!()const;
	Point operator+()const;
	friend ostream& operator<<(ostream&, const Point&);

	double getX(void){return m_x;}
	double getY(void){return m_y;}
	double getZ(void){return m_z;}
};

Point Point::operator-()const{
	return Point(-m_x, -m_y, -m_z);
}

Point Point::operator+()const{
	return Point(m_x, m_y, m_z);
}

bool Point::operator!()const{
	return (m_x==0 && m_y==0 && m_z==0);
}

ostream& operator<<(ostream& out, const Point& point){
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
}

int main(int argc, char const *argv[]){
	Point point(2, 2.3, 5);
	if(!point){
		cout << "Point is set at origin\n";
	}
	else{
		cout << "Point is not at origin\n";
	}

	cout << -(-point) << endl;
	return 0;
}