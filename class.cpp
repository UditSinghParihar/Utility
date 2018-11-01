#include <iostream>
#include <stdio.h>
using namespace std;

struct date_stuct{
	int date;
	int month;
	int year;
};

class date_class{
	int date;
	int month;
	int year;
public:
	date_class(int d = 0, int m = 0, int y = 0):
	date{d}, month{m}, year{y}{}
	void print_class(void);
	const int get_year(void){
		return year;
	}
};

void date_class::print_class(void){
	fprintf(stdout,"%d / %d / %d \n", date, month, year);
} 

int main(int argc, char const *argv[]) {
	date_class obj1{2, 3, 4};
	date_stuct obj2{5, 6, 7};
	obj1.print_class();
	int year = obj1.get_year();
	year = 5;
	cout << year << endl;
	return 0;
}