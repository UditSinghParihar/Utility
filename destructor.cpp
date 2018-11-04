#include <iostream>

using namespace std;

class HelloWorld{
private:
	char *m_data;
public:
	HelloWorld(){
		m_data = new char[14];
		const char* init = "Hello, World!";
		for(int i=0; i<14; ++i){
			m_data[i] = init[i];
		} 
	};
	~HelloWorld(){
		cout << "Inside destructor\n";
		delete[] m_data;
	};
	void print(void)const{
		cout << m_data << endl;
	}
};

int main(int argc, char const *argv[]){
	HelloWorld obj;
	obj.print();
	return 0;
}