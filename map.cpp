#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct StudentGrade{
	string name;
	char grade;
};

class GradeMap{
	vector<StudentGrade> m_map;
public:
	GradeMap(){};
	char& operator[](string student_name){
		for(auto& student : m_map){
			if(student.name == student_name){
				return student.grade;
			}
		}
		m_map.push_back(StudentGrade{student_name, ' '});
		return m_map.back().grade;
	}	
};

int main(int argc, char const *argv[]){
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	cout << "Joe has a grade of: " << grades["Joe"] << endl;
	cout << "Frank has a grade of: " << grades["Frank"] << endl;
	return 0;
}