#include <iostream>
using namespace std;

class cube{
	private:
		int height;
		int length;
		int breath;
		int volume;
	public:
		cube(int l = 2, int b = 3, int h = 4){
			cout << "Constructor called !!\n";
			height = h;
			breath = b;
			length = l;
			volume = h*b*l;
		}
		bool compare(cube obj){
			return this->volume > obj.volume;
		}
};


int main(int argc, char const *argv[])
{
	cube obj1(2, 3, 30);
	cube obj2(2, 3, 20);
	if(obj1.compare(obj2))
		cout << "obj1 is bigger\n";
	else
		cout << "obj2 is bigger\n";
	return 0;
}