#include <iostream>
#include <vector>

using namespace std;

class Point{
private:
	int m_x;
	int m_y;
	int m_z;

public:
	Point(int x=0, int y=0, int z=0): m_x{x}, m_y{y}, m_z{z}{};
	
	friend ostream& operator<<(ostream& out, const Point& p){
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Shape{
public:
	Shape(){};
	virtual ~Shape(){};

	virtual ostream& print(ostream& out)const = 0;

	friend ostream& operator<<(ostream& out, const Shape& sh){
		return sh.print(out);
	}
};

class Triangle : public Shape{
private:
	Point m_a;
	Point m_b;
	Point m_c;

public:
	Triangle(const Point& a, const Point& b, const Point& c): m_a{a}, m_b{b}, 
	m_c{c}{};

	~Triangle(){};
	
	virtual ostream& print(ostream& out)const override{
		out << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ")";
		return out;
	}
};

class Circle : public Shape{
private:
	Point center;
	int radius;

public:
	Circle(const Point& c, int r): center{c}, radius{r}{};
	
	~Circle(){};
	
	virtual ostream& print(ostream& out)const override{
		out << "Circle(" << center << ", radius " << radius << ")";
		return out;
	}

	int getRadius(void)const{return radius;}
};

int getLargestRadius(const auto& v){
	int maxRadius = -10000;
	for(const auto &sh : v){
		Circle *cr = dynamic_cast<Circle*>(sh);
		if(cr != nullptr){
			int radius = cr->getRadius();
			if(radius > maxRadius)
				maxRadius = radius;
		}
	}
	return maxRadius;
}

int main(int argc, char const *argv[]){
	// Circle c(Point(1, 2, 3), 7);
	// std::cout << c << '\n';
 
	// Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
	// std::cout << t << '\n';

 //    std::vector<Shape*> v;
	// v.push_back(new Circle(Point(1, 2, 3), 7));
	// v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	// v.push_back(new Circle(Point(4, 5, 6), 3));
 
	// for(const auto &sh : v){
	// 	cout << *sh << endl;
	// }
 
	// std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function
 
	// for(const auto &sh : v){
	// 	delete sh;
	// }

	int a = 5;
	const int *b = &a;
	// *b = 6;
	// cout << a << endl;
	delete b;

	return 0;
}