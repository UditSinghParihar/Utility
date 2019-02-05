#include <iostream>
#include <algorithm>

using namespace std;

class MultiplyX{
private:
	int num;

public:
	MultiplyX(int x): num{x}{};
	
	int operator()(int multiplier){
		return num*multiplier;
	}	
};

void print_vector(const vector<int>& output){
	for(auto element : output){
		cout << element << endl;
	}
}

int main(int argc, char const *argv[]){
	// MultiplyX multiply_5(5);
	// cout << multiply_5(10) << endl;

	vector<int> input{2, 3, 14, 10};
	vector<int> output(input.size());

	std::transform(input.begin(), input.end(), output.begin(), MultiplyX(10));
	print_vector(output);

	return 0;
}