#include <iostream>

using namespace std;

class Average{
private:
	float m_sum;
	int m_number_count;
public:
	Average(float sum=0.0, int number_count=0):
	m_sum{sum},
	m_number_count{number_count}{};

	Average& operator+=(int number){
		m_sum += number;
		++m_number_count;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Average& average){
		out << float(average.m_sum/average.m_number_count);
		return out;
	}
};

int main(int argc, char const *argv[]){
	Average avg;
	
	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4
	
	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6
 
	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12
 
	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5
 
	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7
 
	Average copy = avg;
	std::cout << copy << '\n';
 
	return 0;
}