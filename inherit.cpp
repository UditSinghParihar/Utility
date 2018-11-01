#include <iostream>
#include <string>

using namespace std;

class Person{
private:
	int m_age;
	string m_name;
public:
	Person(string name="", int age=0){
		cout << "Person::constructor called\n";
		set_name_and_age(name, age);
	};
	void get_name_and_age(void){
		fprintf(stdout, "Name: %s\t age: %d\n", m_name.c_str(), m_age);
	}
	void set_name_and_age(string name, int age){
		m_name = name;
		m_age = age;
	}
};

class Employee: public Person{
private:
	int m_id;
	double m_salary;
public:
	Employee(string name, int age, int id=0, double salary=0.0):Person{name, age}, m_id{id}, m_salary{salary}{
		cout << "Employee::constructor called\n";
	};
	void get_id_salary(void){
		fprintf(stdout, "Id: %d\t salary: %g\n", m_id, m_salary);
	}
};

int main(int argc, char const *argv[]){
	Employee emp1{"Harry", 21, 5, 20000};
	emp1.get_name_and_age();
	emp1.get_id_salary();
	return 0;
}