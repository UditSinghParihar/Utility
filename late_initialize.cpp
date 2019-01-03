#include <iostream>
#include <vector>

using namespace std;

class Late{
private:
	vector<int> list;
public:
	Late(){};
	void fill_list(void){
		list = vector<int>{2, 3, 5};	
	}
};

int main(int argc, char const *argv[]){
	Late list;
	list.fill_list();
	return 0;
}