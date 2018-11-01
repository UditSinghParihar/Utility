#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

class Vector{
private:
	int m_x, m_y, m_z;
public:
	Vector(int x=0, int y=0, int z=0):m_x{x}, m_y{y}, m_z{z}{};	
	void print(void);
	friend void Point::add_vector(Vector &);
};


#endif