#include <iostream>
#include <chrono>

using namespace std;

class Timer{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now()){}
	
	void reset(){
		m_beg = clock_t::now();
	}
	
	double elapsed() const{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

constexpr long int fib(int num){
	return num>=1 ? fib(num-1) + fib(num-2) : 1;
}

int main(int argc, char const *argv[]){
	Timer timer;
	const long int result = fib(100);
	const long int num1 = fib(99);
	const long int num2 = fib(98);
	cout << "Time relapsed: " << timer.elapsed() << endl;

	fprintf(stdout, "fib(99) = %ld\tfib(98) = %ld\nfib(100) = %ld\tsummation is %ld\n",
			num1, num2, result, num1+num2);
	return 0;
}