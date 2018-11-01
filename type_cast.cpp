#include <iostream>
#include <string>

using namespace std;

class Fruit{
private:
	int m_id;
	string m_name;
public:
	Fruit(int id=0, string name=""):m_id{id}, m_name{name}{};
	friend ostream& operator<<(ostream &out, const Fruit &obj){
		out << "Fruit id: " << obj.m_id << "name: " << obj.m_name;
		return out;
	}
	void get_info(void){
		fprintf(stdout, "Name: %s\tid: %d\n", m_name.c_str(), m_id);
	}
};

class Apple:public Fruit{
private:
	string m_color;
public:
	Apple(int id, string name, string color):Fruit{id, name}, m_color{color}{};
	void get_info(void){
		Fruit::get_info();
		fprintf(stdout, "Color: %s\n", m_color.c_str());
	}
};

int main(int argc, char const *argv[]){
	Apple obj(32, "George", "Red");
	obj.get_info();
	return 0;
}