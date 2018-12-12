#include <iostream>

using namespace std;

class IntArray{
private:
	int* m_data;
	int m_length;

public:
	IntArray(int length): m_length{length}{
		m_data = new int[m_length];
	};

	~IntArray(){
		delete[] m_data;
	};

	IntArray(const IntArray& array){
		cout << "Inside copy constructor\n";
		m_length = array.m_length;
		m_data = new int[m_length];
		for(int i=0; i<m_length; ++i){
			m_data[i] = array.m_data[i];			
		}
	}

	int& operator[](int index){
		return m_data[index];
	}

	IntArray& operator=(IntArray& array){
		if(this == &array){
			return *this;
		}

		delete[] m_data;
		m_length = array.m_length;
		m_data = new int[m_length];
		for(int i=0; i<m_length; ++i){
			m_data[i] = array.m_data[i];
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, IntArray& array){
		for(int i=0; i<array.m_length; ++i){
			out << array[i] << " ";
		}
		return out;
	}
	
};

IntArray fillArray(void){
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
 
	return a;
}
 
int main(int argc, char const *argv[]){
	IntArray array1(5);
	array1[0] = 5;
	array1[1] = 8;
	array1[2] = 2;
	array1[3] = 3;
	array1[4] = 6;
	IntArray a = array1;
	std::cout << a << '\n';
 
	IntArray b(1);
	a = a;
	b = a;
 
	std::cout << b << '\n';
 
	return 0;
}