#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class MyString{
private:
	char* m_data;
	int m_length;

public:
	MyString(const char* data=""){
		assert(data);
		m_length = strlen(data);
		m_data = new char[m_length];
		for(int i=0; i<m_length; ++i){
			m_data[i] = data[i];
		}
	};

	MyString(const MyString& source){
		m_length = source.m_length;
		m_data = new char[m_length];
		for(int i=0; i<m_length; ++i){
			m_data[i] = source.m_data[i];			
		}	
	};

	MyString& operator=(const MyString& source){
		if(this == &source){
			return *this;
		}

		delete[] m_data;
		m_length = source.m_length;
		m_data = new char[m_length];
		for(int i=0; i<m_length; ++i){
			m_data[i] = source.m_data[i];
		}
		return *this;
	}

	~MyString(){
		cout << "Inside destructor\n";
		delete[] m_data;
	};
	
	char* get_string(void){
		return m_data;
	}

	int get_length(void){
		return m_length;
	}
};

int main(int argc, char const *argv[]){
	MyString hello{"Hello"};
	{
		MyString copy_string2;
		copy_string2 = hello;
	}
	cout << hello.get_string() << endl;
	return 0;
}