#include <iostream>

using namespace std;

class Fraction{
	int m_numerator;
	int m_denominator;
public:
	Fraction(int numerator=0, int denominator=1):
	m_numerator{numerator}, m_denominator{denominator}{
		reduce();
	};
	
	static int gcd(int num1, int num2){
		return (num2==0) ? num1 : gcd(num2, num1%num2);	
	}
	
	void reduce(void){
		int devisor = gcd(m_numerator, m_denominator);
		m_numerator /= devisor;
		m_denominator /= devisor;
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
 	friend istream& operator>>(istream& in, Fraction& fraction);
 	friend ostream& operator<<(ostream& out ,const Fraction& fraction);

	void print(){
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
};
 
	Fraction operator*(const Fraction &f1, const Fraction &f2){
		return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
	}
	 
	Fraction operator*(const Fraction &f1, int value){
		return Fraction(f1.m_numerator * value, f1.m_denominator);
	}
	 
	Fraction operator*(int value, const Fraction &f1){
		return Fraction(f1.m_numerator * value, f1.m_denominator);
	}

	istream& operator>>(istream& in, Fraction& fraction){
		in >> fraction.m_numerator;
		in >> fraction.m_denominator;
		return in;
	}

	ostream& operator<<(ostream& out, const Fraction& fraction){
		out << fraction.m_numerator << "/" << fraction.m_denominator;
		return out;
	}

int main(int argc, char const *argv[]){
	Fraction f1;
	cout << "Enter fraction 1:\n";
	cin >> f1;
	Fraction f2;
	cout << "Enter fraction 2:\n";
	cin >> f2;

	cout << f1 << " * " << f2 << " is " << f1*f2 << endl;	
	return 0;
}