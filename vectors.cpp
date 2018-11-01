#include <iostream>

using namespace std;

class Vector;

class Point{
private:
	int m_x;
	int m_y;
	int m_z;
public:
	Point(int x=0, int y=0, int z=0):m_x{x},m_y{y},m_z{z}{};
	void print(void){
		fprintf(stdout,"Point\nx:%d y:%d z:%d\n", m_x, m_y, m_z);
	}
	void move_by_vector(const Vector& v);
};

class Vector{
private:
	int m_x, m_y, m_z;
public:
	Vector(int x=0, int y=0, int z=0){
		m_x=x;
		m_y=y;
		m_z=z;
	};
	void print(void){
		fprintf(stdout,"Vector\nx:%d y:%d z:%d\n", m_x, m_y, m_z);
	}
	friend void Point::move_by_vector(const Vector&);
};

void Point::move_by_vector(const Vector& v){
		m_x += v.m_x;
		m_y += v.m_y;
		m_z += v.m_z;
	}



int main(int argc, char const *argv[]){
	Point P(1,2,3);
	Vector V(10, 100 , 20);
	P.print();
	P.move_by_vector(V);
	P.print();
	return 0;
}
