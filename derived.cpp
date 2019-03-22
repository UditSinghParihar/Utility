#include <iostream>

using namespace std;

class Base{
private:
	int m_id;
public:
	Base(int id): m_id{id}{};
	
	friend ostream& operator<<(ostream& out, const Base& obj){
		out << "In Base\n" << "id: " << obj.m_id << endl;
		return out;
	}

	int get_id(void){return m_id;}
};

class Derived : public Base{
private:
public:
	Derived(int id): Base{id}{};
	
	friend ostream& operator<<(ostream& out, const Derived& obj){
		out << "In Derived\n" << "id: \n" << static_cast<Base>(obj);
		return out;
	}
	
	int get_id() = delete;
};

int main(int argc, char const *argv[]){
	Derived obj{6};
	// cout << obj;
	cout << obj.Base::get_id() << endl;
	return 0;
}