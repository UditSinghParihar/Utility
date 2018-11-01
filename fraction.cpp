#include <iostream>

using namespace std;

class Fraction{
private:
	int m_num;
	int m_denom;
public:
	Fraction(int num=0, int denom=1):m_num{num}, m_denom{denom}{};
	void print(void){
		int gcd = find_gcd(m_num, m_denom);
		fprintf(stdout, "%d/%d\n", m_num/gcd, m_denom/gcd);
	}
	friend Fraction operator*(const Fraction &obj1, const Fraction &obj2){
		return Fraction(obj1.m_num * obj2.m_num, obj1.m_denom * obj2.m_denom);
	}
	friend Fraction operator*(const Fraction &obj , const int number){
		return Fraction(obj.m_num * number, obj.m_denom);
	}
	friend Fraction operator*(const int number, const Fraction &obj){
		return Fraction(obj.m_num * number, obj.m_denom);
	}
	int find_gcd(int a, int b){
		return (b==0) ? ((a>0) ? a : -a ) : find_gcd(b, a % b);
	}
};

int main(int argc, char const *argv[]){
	Fraction f1(2, 5);
	f1.print();
	Fraction f2(3, 8);
	f2.print();
	Fraction f3 = f1 * f2;
	f3.print();
	Fraction f4 = f1 * 2;
	f4.print();
	Fraction f5 = 2 * f2;
	f5.print();
	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();
	return 0;
}