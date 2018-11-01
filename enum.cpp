#include <iostream>

using namespace std;

class fruit{
private:
	int m_fruit;
public:
	const static int sm_fruit = 5;
	fruit(int fruit):m_fruit{fruit}{};
};

int main(int argc, char const *argv[]){
	enum week{sunday, monday, tuesday, wednesday}today;
	cout << today << endl << monday << endl << tuesday << endl;
	cout << "fruit member: "<< fruit::sm_fruit << endl;
	return 0;
}