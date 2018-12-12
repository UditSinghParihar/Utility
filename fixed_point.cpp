#include <iostream>

using namespace std;

class FixedPoint2{
private:
	int m_whole;
	int m_fraction;

	int get_abs(int number){
		if(number<0)
			return -number;
		else
			return number;
	}

public:
	FixedPoint2(int whole=0, int fraction=0){
		if(whole<0 || fraction<0){
			m_whole = -get_abs(whole);
			m_fraction = -get_abs(fraction);
		}
		else{
			m_whole = whole;
			m_fraction = fraction;
		}
	};
	
	operator double()const{
		return m_whole + double(m_fraction * 0.01);
	}

	friend ostream& operator<<(ostream& out, const FixedPoint2& number){
		double sum = number.m_whole + 0.01*number.m_fraction;
		out << sum;
		return out;
	}
};

int main()
{
	FixedPoint2 a(34, 56);
	std::cout << a << '\n';
 
	FixedPoint2 b(-2, 8);
	std::cout << b << '\n';
 
	FixedPoint2 c(2, -8);
	std::cout << c << '\n';
 
	FixedPoint2 d(-2, -8);
	std::cout << d << '\n';
 
	FixedPoint2 e(0, -5);
	std::cout << e << '\n';
 
	std::cout << static_cast<double>(e) << '\n';
 
	return 0;
}