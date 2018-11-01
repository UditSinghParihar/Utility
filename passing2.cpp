#include <iostream>
#include <tuple>
#include <string>

using namespace std;

struct data{
	int m_x;
	double m_y;	
};

struct Employee{
	string name;
	int id;
};

data return_value(int a, double b){
	data S;
	S.m_x = ++a;
	S.m_y = ++b;
	return S;
}

class something{
private:
	string m_name;
public:
	something(string name):m_name{name}{};
	string get_name(void)const{
		return m_name;
	}
};

void print_employee(const Employee& obj){
	cout << "Employee name: " << obj.name << endl;
}

int main(int argc, char const *argv[]){
	int a=2;
	double b=5.3;
	data S = return_value(a,b);
	cout << "a: " << S.m_x << "\tb: " << S.m_y << endl;
	Employee obj{"John", 23};
	print_employee(obj);
	const something obj2{"Robin"};
	cout << obj2.get_name() << endl;
	something obj3{"Rahul"};
	cout << obj3.get_name() << endl;
	return 0;
}