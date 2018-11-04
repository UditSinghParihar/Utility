#include <iostream>
#include <string>

using namespace std;

enum ItemType{
	ITEM_SWORD,
	ITEM_SHIELD,
	ITEM_PORTION,	
};

enum MonsterType{
	MONSTER_ORCS,
	MONSTER_GOBLINS,
	MONSTER_TROLLS,
	MONSTER_OGRES,
	MONSTER_SKELETONS,
};

string get_item_type(ItemType obj){
	switch(obj){
		case ITEM_SWORD:
			return string("sword");
		case ITEM_SHIELD:
			return string("shield");
		case ITEM_PORTION:
			return string("portion");
		default:
			return string("Unknown item");
	}
}

int main(int argc, char const *argv[]){
	ItemType item = ITEM_PORTION;
	cout << get_item_type(item) << endl;
	MonsterType monster{MONSTER_TROLLS};
	return 0;
}