#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal{
protected:
	string m_name;
	string m_speak;

public:
	Animal(const string& name, const string& speak=""): m_name{name}, m_speak{speak}
	{};
	
	const string& getName(void){return m_name;}
	const string& speak(void){return m_speak;}
};

class Cat : public Animal{
public:
	Cat(const string& name): Animal(name, "Meow"){};
};

class Dog : public Animal{
public:
	Dog(const string& name): Animal(name, "Woof"){};
};

int main(){
    Cat fred("Fred"), misty("Misty"), zeke("Zeke");
    Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");
 
    vector<Animal*> animals{&fred, &garbo, &misty, &pooky, &truffle, &zeke};
    for(const auto &animal : animals)
		std::cout << animal->getName() << " says " << animal->speak() << '\n';
 
    return 0;
}