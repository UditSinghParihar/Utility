#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Doctor;

class Patient{
private:
	string m_name;
	vector<Doctor*> m_doctors;
	void add_doctor(Doctor* doc);

public:
	Patient(const string& name):m_name{name}{};

	string get_name(void)const{ return m_name;}

	friend ostream& operator<<(ostream& out, const Patient& pat);
	friend Doctor;
};

class Doctor{
private:
	string m_name;
	vector<Patient*> m_patients;

public:
	Doctor(const string& name):m_name{name}{};

	void add_patient(Patient* pat){
		m_patients.push_back(pat);
		pat->add_doctor(this);
	}

	string get_name(void)const{ return m_name;}

	friend ostream& operator<<(ostream& out, const Doctor& doc){
		out << "Doctor " << doc.get_name() << " is seeing patients: " << endl;
		for(int i=0; i<doc.m_patients.size(); ++i){
			out << doc.m_patients[i]->get_name() << endl;
		}
		return out;
	}
		
};

void Patient::add_doctor(Doctor* doc){
	m_doctors.push_back(doc);
}

ostream& operator<<(ostream& out, const Patient& pat){
	out << "Patient " << pat.get_name() << " is seeing doctors: " << endl;
	for(int i=0; i<pat.m_doctors.size(); ++i){
		out << pat.m_doctors[i]->get_name() << endl;
	}
	return out;
}

int main(int argc, char const *argv[]){
	Doctor* d1 = new Doctor("Sam");
	Doctor* d2 = new Doctor("Binny");
	Patient* p1 = new Patient("Jinny");
	Patient* p2 = new Patient("Honey");

	d1->add_patient(p1);
	d1->add_patient(p2);
	d2->add_patient(p1);

	cout << *d1 << endl;
	cout << *p1 << endl;

	delete d1;
	delete d2;
	delete p1;
	delete p2;
	
	return 0;
}