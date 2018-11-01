#ifndef POINT_H
#define POINT_H

class Vector; 

class Point{
	int m_x, m_y, m_z;
public:
	Point(int x=0, int y=0, int z=0):m_x{x},m_y{y},m_z{z}{};
	void print(void);
	void add_vector(Vector &);
};

#endif
