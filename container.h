#ifndef CONTAINER_H
#define CONTAINER_H

#include<assert.h>

class intarray{
private:
	int m_length;
	int* m_data;
public:
	intarray(int length):m_length{length}{
		m_data = new int[length];
	};
	~intarray(){
		delete[] m_data;
	};
	void set_value(int value, int index){
		if(index >= 0 && index < m_length){
			m_data[index] = value;
		}
		else
			return;
	}
	void erase(void){
		delete[] m_data;
		m_data = nullptr;		
		m_length = 0;
	}
	int& operator[](int index){
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	int get_size(void){
		return m_length;
	}
	void reallocate(int length){
		erase();
		m_data = new int[length];
		m_length = length;
	}
	void insert_before(int index, int value){
		assert(index >= 0 && index < m_length);
		int* temp = new int[m_length + 1];
		int i=0;
		for(; i<index; i++)
			temp[i] = m_data[i];
		temp[i] = value;
		for(; i < (m_length); i++)
			temp[i+1] = m_data[i];
		int temp_length = m_length +1;
		delete[] m_data;
		m_data = temp;
		++m_length;
	}
};

#endif