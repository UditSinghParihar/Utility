#include <iostream>

using namespace std;

struct Poses{
	static int counter;
	const int id;
	Poses(): id{counter}{
		++counter;
	};
};

int Poses::counter = 1;

int main(int argc, char const *argv[]){
	Poses a, b, c;
	fprintf(stdout, "%d\n%d\n%d\n", a.id, b.id, c.id);
	return 0;
}