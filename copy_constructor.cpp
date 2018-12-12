#include <iostream>
#include <cassert>

using namespace std;

class Fraction{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator=0, int denominator=1):m_numerator{numerator}, m_denominator{denominator}{
		assert(m_denominator != 0);
	};
	
	Fraction(const Fraction& fraction):
		m_numerator{fraction.m_numerator}, m_denominator{fraction.m_denominator}{
			cout << "Copy constructor called\n";
		};
	
	friend ostream& operator<<(ostream& out, const Fraction& fraction){
		out << fraction.m_numerator << "/" << fraction.m_denominator;
		return out;
	}

	void set_numerator(int numerator){
		m_numerator = numerator;
	}

	int get_numerator(void){
		return m_numerator;
	}
};

Fraction make_negative_value(Fraction fraction){
	fraction.set_numerator(-fraction.get_numerator());
	return fraction;
}

void make_negative_reference(Fraction& fraction){
	fraction.set_numerator(-fraction.get_numerator());	
}

int main(int argc, char const *argv[]){
	Fraction five_thirds(5, 3);
	cout << five_thirds << endl;
	Fraction fraction_copy(Fraction(2, 4));
	cout << fraction_copy << endl;
	Fraction fraction1(2, 3);
	Fraction fraction2(4, 3);
	cout << "fraction1 value: " << fraction1 << endl;
	cout << "fraction1 negative by value: " << make_negative_value(fraction1) << endl;
	make_negative_reference(fraction2);
	cout << "fraction2 negative by reference: " << fraction2 << endl;
	Fraction fraction3 = five_thirds;
	return 0;
}