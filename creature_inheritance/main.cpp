#include <iostream>

#include "creature.h"

using namespace std;

int main(int argc, char const *argv[]){
	Creature creature{"Dog", Point{2, 3}};
	cout << creature; 
	return 0;
}