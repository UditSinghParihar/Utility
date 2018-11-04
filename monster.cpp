#include <iostream>
#include <string>

using namespace std;

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

class Monster{
private:
	MonsterType m_type;
	string m_name;
	string m_roar;
	int m_hit_points;
public:
	Monster();
	
};

int main(int argc, char const *argv[]){

	return 0;
}