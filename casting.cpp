#include <iostream>

using namespace std;

class Cents{
private:
	int m_cents;
public:
	Cents(int cents=0):m_cents{cents}{};
	
	operator int(){
		return  m_cents;
	}

	int get_cents(void){
		return m_cents;
	}

	void set_cents(int cents){
		m_cents = cents;
	}
};

class Dollars{
private:
	int m_dollars;
public:
	Dollars(int dollars):m_dollars{dollars}{};

	operator Cents(){
		return Cents(m_dollars * 100);
	}
	
};

void print_cents(Cents cents){
	cout << cents << endl;
}

int main(int argc, char const *argv[]){
	Dollars dollars(9);
	print_cents(dollars);
	return 0;
}