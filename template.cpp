#include <iostream>

using namespace std;

template <typename T>
const T& my_max(const T &a, const T &b){
	return (a>b)? a:b;
}

template <typename T>
const T my_sum(T* arr , int length){
	T value{0};
	for(int i=0; i<length; ++i)
		value += arr[i];
	return value;
}

class Cents{
private:
	int cent;
public:
	Cents(int value):cent{value}{};
	void operator +=(Cents& obj){
		cent += obj.cent;
		return ;
	}
	friend std::ostream& operator << ( std::ostream &out, const Cents &obj){
		out << obj.cent << " cents ";	
		return out;
	}
};

int main(int argc, char const *argv[]){
	cout << my_max(2,3) << endl << my_max(3.4, 11.5) << endl << my_max('a', 'z') << endl;
	const int length = 3;
	double arr[length]{2.3, 1.1, 2};
	cout << my_sum(arr, length) << endl;

	Cents array[length] = {Cents{3}, Cents{10}, Cents{20}};
	cout << my_sum(array, length) << endl;
	return 0;
}