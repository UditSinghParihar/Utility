#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Teacher{
private:
	string m_name;

public:
	Teacher(string name): m_name{name}{};

	string getName(void){
		return m_name;
	}
};

class Department{
private:
	vector<Teacher*> m_teachers;

public:
	Department(Teacher* teacher=nullptr){
		if(teacher != nullptr){
			m_teachers.push_back(teacher);
		}
	};
	
	void add(Teacher* teacher){
		m_teachers.push_back(teacher);
	}

	friend ostream& operator<<(ostream& out, const Department& dept){
		out << "Department: ";
		for(int i=0; i<dept.m_teachers.size(); ++i){
			out << dept.m_teachers[i]->getName() << " ";
		}
		return out;
	} 
};

int main(int argc, char const *argv[]){
	Teacher *t1 = new Teacher("Bob");
	Teacher *t2 = new Teacher("Frank");
	Teacher *t3 = new Teacher("Beth");

	{
		Department dept;
		dept.add(t1);
		dept.add(t2);
		dept.add(t3);
		
		cout << dept << endl;
	}

	cout << t1->getName() << "\t" << t2->getName() << "\t" << t3->getName() << endl;

	delete t1;
	delete t2;
	delete t3;

	return 0;
}