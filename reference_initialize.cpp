#include <iostream>

using namespace std;

class Foo{
private:
	int& m_number;

public:
	Foo(int& number) : m_number{number}{};
	
	void set_number(int number){
		m_number = number;
	}

	int get_number(void){
		return m_number;
	}
};

int main(int argc, char const *argv[]){
	int number=10;
	Foo value{number};
	++number;
	fprintf(stdout, "%d\t%d\n", number, value.get_number());
	return 0;
}