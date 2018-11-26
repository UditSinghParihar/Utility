#include <iostream>

using namespace std;

class Accumulate{
private:
	int counter;
public:
	Accumulate(int arg_num=0):counter{arg_num}{};
	
	int operator()(int num){
		return counter += num;
	}
};

int main(int argc, char const *argv[]){
	Accumulate sum;
	cout << sum(10) << "\n";
	cout << sum(20) << "\n";
	cout << sum(30) << "\n";
	cout << sum(100) << "\n\n";

	Accumulate sum2;
	cout << sum2(10) << "\t" << sum2(20) << "\t" << sum2(30) << "\t" << sum2(100) << endl;
	return 0;
}