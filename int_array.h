#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <assert.h>

template <typename T>

class MYARRAY{
private:
	int m_length;
	T *m_data;	
public:
	void reallocate(int length){
		m_data = new T[length];
		m_length = length;
	}
	MYARRAY(int length){
		reallocate(length);
	};
	MYARRAY(const std::initializer_list<T>& list):MYARRAY(list.size()){
		int index=0;
		for(auto& element : list){
			m_data[index] = element;
			++index;
		}
	}
	MYARRAY& operator=(const std::initializer_list<T>& list){
		if(m_data!=nullptr)
			delete[] m_data;
		m_length = list.size();
		m_data = new T[m_length];

		int index=0;
		for(auto& element : list){
			m_data[index] = element;
			++index;
		}
		return *this;
	}
	~MYARRAY(){
		delete[] m_data;
		std::cout << "Destructor called.\n";
	};
	void erase(void){
		delete[] m_data;
		m_length = 0;
		m_data = nullptr;
	}
	int get_length(void){
		return m_length;
	}
	T& operator[](int index){
		assert(index >=0 && index < m_length);
		return m_data[index];
	}
	friend std::ostream& operator<<(std::ostream &out, MYARRAY &obj){
		for(int i=0; i<obj.m_length; ++i)
			out << obj[i] << " ";
		return out;
	}
	void insert(T value, int index){
		assert(index >=0 && index < m_length);
		T *temp = new T[m_length+1];
		for(int i=0, j=0; i<=m_length; ++i){
			if(i != index){
				temp[i] = m_data[j];
				++j;
			}
			else
				temp[i] = value;
		}
		delete[] m_data;
		++m_length;
		m_data = temp;
	}
	void pop(void){
		T *temp = new T[m_length-1];
		for(int i=0; i<m_length-1; ++i){
			temp[i] = m_data[i];
		}
		delete[] m_data;
		--m_length;
		m_data = temp;
	}
};

#endif