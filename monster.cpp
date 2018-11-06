#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Monster{
public:
	enum MonsterType{
		MONSTER_DRAGON,
		MONSTER_GOBLIN,
		MONSTER_OGRE,
		MONSTER_ORC,
		MONSTER_SKELETON,
		MONSTER_TROLL,
		MONSTER_VAMPIRE,
		MONSTER_ZOMBIE,
		MAX_MONSTER_TYPES = 8,
	};
private:
	MonsterType m_type;
	string m_name;
	string m_roar;
	int m_hit_points;
public:
	Monster(MonsterType type, string name, string roar, int hit_points):
	m_type{type},
	m_name{name},
	m_roar{roar},
	m_hit_points{hit_points}{};
	string getTypeString(const MonsterType type)const{
		switch(type){
			case MONSTER_DRAGON:
				return string("MONSTER_DRAGON");
			case MONSTER_GOBLIN:
				return string("MONSTER_GOBLIN");
			case MONSTER_OGRE:
				return string("MONSTER_OGRE");
			case MONSTER_ORC:
				return string("MONSTER_ORC");	
			case MONSTER_SKELETON:
				return string("MONSTER_SKELETON");
			case MONSTER_TROLL:
				return string("MONSTER_TROLL");
			case MONSTER_VAMPIRE:
				return string("MONSTER_VAMPIRE");
			case MONSTER_ZOMBIE:
				return string("MONSTER_ZOMBIE");
		}
		return string("Unknown Monster");
	}
	void print(void)const{
		fprintf(stdout, "%s the %s has %d hit points and says %s\n", m_name.c_str(),
				getTypeString(m_type).c_str(), m_hit_points, m_roar.c_str());
	}
};

class MonsterGenerator{
public:
	static int getRandomNumber(const int min, const int max){
		static const double ratio = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		srand(time(0));
		return static_cast<int>(rand() * ratio * (max - min + 1) + min);
	}

	MonsterGenerator();
	static Monster generateMonster(void){
		static vector<string> names {"mana", "manas", "rohan", "rohit", "sachin", "mando"};
		static vector<string> roars {"hiss", "po", "bho", "ho", "dhahar", "meow"};
		Monster::MonsterType rand_type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
		return Monster(rand_type, names[getRandomNumber(0, 5)], roars[getRandomNumber(0, 5)], getRandomNumber(1, 100));
	}
};

int main(int argc, char const *argv[]){
	Monster generated = MonsterGenerator::generateMonster();
	generated.print();	
	return 0;
}