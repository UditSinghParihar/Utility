#include "Point.h"
#include "Vector.h"
#include <iostream>

void Point::print(void){
	fprintf(stdout, "Point: x:%d y:%d z:%d\n", m_x, m_y, m_z);
}

void Point::add_vector(Vector &v){
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}