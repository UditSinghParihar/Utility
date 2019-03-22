#include <iostream>
#include <string>

using namespace std;

class Fruit{
private:
	string m_name;
	string m_color;
public:
	Fruit(const string& name, const string& color): m_name{name}, m_color{color}{};

	string get_name(void)const{return m_name;}
	string get_color(void)const{return m_color;}
};

class Apple: public Fruit{
private:
	float m_fiber;
public:
	Apple(const string& name="", const string& color="", float fiber=0):
	Fruit{name, color}, m_fiber{fiber}{};

	float get_fiber(void)const{return m_fiber;}

	friend ostream& operator<<(ostream& out, const Apple& obj){
		out << "Apple(" << obj.get_name() << ", "<< obj.get_color() << ", " <<
		obj.get_fiber() << ")\n";
		return out;
	}
};

class Banana: public Fruit{
public:
	Banana(const string& name="", const string& color=""): Fruit{name, color}{};

	friend ostream& operator<<(ostream& out, const Banana& obj){
		out << "Banana(" << obj.get_name() << ", "<< obj.get_color() << ")\n";
		return out;
	}
};

int main(){
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;
 
	const Banana b("Cavendish", "yellow");
	std::cout << b;
 
	return 0;
}