#include <iostream>

using namespace std;

class Base{
public:
	Base(){};

	virtual ostream& print(ostream& out)const{
		out << "Base";
		return out;
	}

	friend ostream& operator<<(ostream& out, const Base& b){
		return b.print(out);
	}
};

class Derived : public Base{
public:
	Derived(){};
	
	virtual ostream& print(ostream& out)const{
		out << "Derived";
		return out;
	}
};

int main(int argc, char const *argv[]){
	Derived d;
	Base b;
	cout << b << endl;
	cout << d << endl;
	Base &b2 = d;
	cout << b2 << endl;

	return 0;
}