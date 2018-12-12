#include <iostream>

using namespace std;

class MyString{
private:
	char* m_data;
	int m_length;

public:
	MyString(const char* data="", int length=0): m_length{length}{
		if(m_length==0){
			m_data = nullptr;
		}	
		else{
			m_data = new char[m_length];
			for(int i=0; i<m_length; ++i){
				m_data[i] = data[i];
			}
		}
	};

	friend ostream& operator<<(ostream& out, const MyString& str){
		out << str.m_data;
		return out;
	}

	MyString& operator=(const MyString& data){
		cout << "Inside assignment operator\n";
		if(this == &data){
			return *this;
		}
		if(m_data){
			delete[] m_data;
		}
		m_length = data.m_length;
		m_data = new char[m_length];
		for(int i=0; i<m_length; ++i){
			m_data[i] = data.m_data[i];
		}
		return *this;
	}

	int get_string_length(void){ 
		return m_length;
	}

	~MyString(){
		cout << "Inside destructor\n";
		delete[] m_data;
	};
};

int main(int argc, char const *argv[]){
	MyString job1{"Actor", 5};
	cout << job1 << endl;
	MyString job2{"Teacher", 7};
	cout << job2 << " Job2 length: " << job2.get_string_length() << endl;
	job2 = job2;
	cout << job2 << " Job2 length: " << job2.get_string_length() << endl;
	return 0;
}