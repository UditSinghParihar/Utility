#include "Point.h"
#include "Vector.h"

int main(int argc, char const *argv[]){
	Point P(1,2,3);
	Vector V(10, 200, 1000);
	P.print();
	P.add_vector(V);
	P.print();	
	return 0;
}