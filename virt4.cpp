#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal{
protected:
	string m_name;

public:
	Animal(const string& name): m_name{name}{}; 
	
	const string& getName(void){return m_name;}
	virtual const string speak(void) = 0;
};

class Cat : public Animal{
public:
	Cat(const string& name): Animal(name){};

	virtual const string speak(void){return "Meow";}
};

class Dog : public Animal{
public:
	Dog(const string& name): Animal(name){};

	virtual const string speak(void){return "Woof";}
};

int main(){
    Cat fred{"Fred"}, misty{"Misty"}, zeke{"Zeke"};
    Dog garbo{"Garbo"}, pooky{"Pooky"}, truffle{"Truffle"};
 
    vector<Animal*> animals{&fred, &garbo, &misty, &pooky, &truffle, &zeke};
    for(const auto &animal : animals)
		std::cout << animal->getName() << " says " << animal->speak() << '\n';
 
    return 0;
}