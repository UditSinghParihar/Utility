#include <iostream>
#include <array>
#include <string>

using namespace std;

class Person{
private:
	int m_age;
	string m_name;
public:
	Person(int age, const string& name): m_age{age}, m_name{name}{};
	int get_age(void)const{ return m_age;}
	string get_name(void)const{return m_name;}
};

class Employee: public Person{
private:
	float m_wage;
	int m_id;
public:
	Employee(float wage=0, int id=0, int age=0, const string& name=""): 
	Person{age, name}, m_wage{wage}, m_id{id}{};
	int get_id(void){ return m_id;}
};

class Supervisor: public Employee{
public:
	array<int,3> subs;
	Supervisor();	
};

int main(int argc, char const *argv[]){
	Employee e1{23, 2, 18, "John"};
	cout << e1.get_name() << ":" << e1.get_id() << endl;

	return 0;
}