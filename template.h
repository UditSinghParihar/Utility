#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
#include <assert.h>

template <typename T>
class INTARR{
private:
	int m_length;
	T* m_data;
public:
	INTARR(int length):m_length{length}{
		m_data = new T[m_length];
		//std::cout << "Inside constructor\n";
	};
	~INTARR(){
		delete[] m_data;
		//std::cout << "Inside destructor\n";
	};
	int get_length(void){
		return m_length;
	}
	T& operator[](int index){
		assert(index>=0 && index<m_length);
		return m_data[index];
	}
	void erase(void){
		delete[] m_data;
		m_length = 0;
		m_data = nullptr;
	}

};

#endif