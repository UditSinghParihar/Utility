#include <iostream>

using namespace std;

class Cents{
private:
	double m_cent;
public:
	Cents(double cent=0): m_cent{cent}{};
	int get_cent(void){
		return m_cent;
	}
	friend ostream& operator << (ostream& out,const Cents &obj){
		out << obj.m_cent << " cents";
		return out;
	}
	void operator +=(Cents obj){
		m_cent += obj.m_cent;
	}
	Cents& operator /(int value){
		m_cent /= value;
		return *this;
	}
	friend bool operator ==(const Cents &obj1, const Cents &obj2){
		return (obj1.m_cent == obj2.m_cent); 
	}
};

template <typename T>
T average(T *arr, int length){
	T sum{};
	for(int i=0; i<length; ++i){
		sum += arr[i];
	}
	return sum/length;
}

int main(int argc, char const *argv[]){
	int arr_i[]{1, 2, 3};
	double arr_d[]{1.1, 2.0, 2.2};
	Cents arr_c[] = {Cents(1.1), Cents(2), Cents(2.2)};
	cout << average(arr_i, 3) << endl << average(arr_d, 3) << endl;
	Cents obj(5);
	cout << obj << endl;
	cout << "average of cent class: " << average(arr_c, 3) << endl;
	cout << (Cents(6) == Cents(6)) << endl; 
	return 0;
}