#include <iostream>
#include <string>

using namespace std;

template <typename T>
class auto_ptr{
private:
	T *m_ptr;
public:
	auto_ptr(T *ptr = nullptr):m_ptr{ptr}{
		cout << "Constructor called\n";
	};
	~auto_ptr(){
		delete m_ptr;
		cout << "Destructor called\n";
	};
	T& operator*(void){
		return *m_ptr;
	}
	T* operator->(void){
		return m_ptr;
	}
	T& operator[](int index){
		return m_ptr[index];
	}
};

class fruit{
private:
	int m_price;
public:
	fruit(int price=0): m_price{price}{};
	int get_price(void){
		return m_price;
	}
};

int main(int argc, char const *argv[]){
	auto_ptr<int> i_ptr(new int);
	*i_ptr = 3;
	auto_ptr<fruit> f_ptr1(new fruit(30));
	cout << *i_ptr << endl << f_ptr1->get_price() << endl;

	auto_ptr<int> arr_ptr(new int[5]);
	for(int i=0; i<5; ++i)
		arr_ptr[i] = i*i;
	return 0;
}