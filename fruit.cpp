#include <iostream>
#include <string>

using namespace std;

class Fruit{
private:
	string m_name;
	string m_color;
public:
	Fruit(string name="", string color=""):m_name{name}, m_color{color}{};
	string get_name(void)const{
		return m_name;
	}
	string get_color(void)const{
		return m_color;
	}
};

class Apple: public Fruit{
private:
	double m_fiber;
public:
	Apple(string name="", string color="", double fiber=0.0):Fruit{name, color}, m_fiber{fiber}{};
	friend ostream& operator << (ostream &out, const Apple &obj){
		out << "Apple(" << obj.get_name() << "," << obj.get_color() << "," << obj.m_fiber << ")";
		return out;
	}
};

class Banana: public Fruit{
public:
	Banana(string name="", string color=""):Fruit{name, color}{};
	friend ostream& operator << (ostream &out, const Banana &obj){
		out << "Banana(" << obj.get_name() << "," << obj.get_color() << ")"; 
		return out;
	}
};

int main(int argc, char const *argv[]){
	const Apple a("Good_apple", "red", 4.2);
	const Banana b("Good_banana", "yellow");
	cout << a << endl << b << endl;
	return 0;
}