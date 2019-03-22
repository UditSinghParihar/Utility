#include <iostream>
#include <string>

using namespace std;

class Fruit{
	string m_name;
	string m_color;
public:
	Fruit(const string& color, const string& name): m_name{name}, m_color{color}{};
	
	string getName(void)const{return m_name;}
	string getColor(void)const{return m_color;}
};

class Apple : public Fruit{
public:
	Apple(const string& color="red", const string& name="apple"): 
	Fruit{color, name}{};
};

class Banana : public Fruit{
public:
	Banana(const string& color="yellow", const string& name="banana"): 
	Fruit{color, name}{};
};

class GrannySmith : public Apple{
public:
	GrannySmith(): Apple{"green", "granny smith apple"}{};	
};

int main(int argc, char const *argv[]){
	Apple a("red");
	Banana b;
	GrannySmith c;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}