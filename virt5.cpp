#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base{
private:
	int m_num;

public:
	Base(int num): m_num{num}{};

	virtual string getName(void){return "Base";}

	int getValue(void){return m_num;}
};

class Dervied : public Base{
public:
	Dervied(int num): Base(num){};
	
	virtual string getName(void){return "Dervied";}
};

void eval(const vector<Base*>& v){
	cout << "v size is: " << v.size() << " and sizeof is: " << sizeof(v) << endl;
}

int main(int argc, char const *argv[]){
	vector<Base*> v;
	v.push_back(new Base(5));
	v.push_back(new Dervied(10));
	v.push_back(new Dervied(6));


	for(const auto e : v){
		fprintf(stderr, "I am %s and my value is %d\n", e->getName().c_str(), 
		e->getValue());
	}
	

	for(auto e : v)
		delete e;

	return 0;
}