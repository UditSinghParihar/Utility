#include <iostream>
#include <memory>

using namespace std;

class rect{
private:
public:
	int width;
	int breath;
	rect(int a = 0, int b = 0){
		width = a;
		breath = b;
	};
	int get_area(void){
		return width * breath;
	}
};

int main(int argc, char const *argv[]){
	auto ptr = std::make_unique<rect>(2, 3);
	cout << ptr->get_area() << endl;
	cout << ptr->width << '\t' << ptr->breath << endl;
	return 0;
}