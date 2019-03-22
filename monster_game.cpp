#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Creature{
protected:
	string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;

public:
	Creature(const string& name, char symbol, int health, int damage, int gold):
				m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage},
				m_gold{gold}{};

	const string& getName(void)const{return m_name;}
	char getSymbol(void)const{return m_symbol;}
	int getHealth(void)const{return m_health;}
	int getDamage(void)const{return m_damage;}
	int getGold(void)const{return m_gold;}
	
	void reduceHealth(int amount){m_health -= amount;}

	bool isDead(void){return (m_health<=0) ? true : false;}

	void addGold(int amount){m_gold += amount;}

	void printStats(void){
		fprintf(stdout, "Name: %s\n"
			"Health remaining: %d.\n"
			"Damaging power: %d.\n"
			"Current Gold amount: %d.\n",
			m_name.c_str(), m_health, m_damage, m_gold);
	}
};

class Player : public Creature{
private:
	int m_level;

public:
	Player(const string& name): Creature{name, '@', 10, 1, 0}, m_level{1}{};

	int getLevel(void){return m_level;}
	
	void leveUp(void){
		++m_level;
		++m_damage;
	}

	bool hasWon(void){return (m_level>=20) ? true : false;}

	void printStats(void){
		cout << "\n---\n";
		fprintf(stdout, "You are now at level %d\n", getLevel());
		Creature::printStats();
		cout << "---\n\n";
	}
};

int getRandomNumber(int min, int max){
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Monster : public Creature{
public:
	enum Type{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	
	struct MonsterData{
		string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];
	
	Monster(Type type): Creature{monsterData[type].name, monsterData[type].symbol,
			monsterData[type].health, monsterData[type].damage, 
			monsterData[type].gold}{}

	static Type getRandomMonster(void){
		return static_cast<Type>(getRandomNumber(0, MAX_TYPES-1));
	};
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

void attackMonster(Player& player, Monster& m){
	m.reduceHealth(player.getDamage());
	fprintf(stdout, "You hit the %s for %d damage.\n", m.getName().c_str(), 
			player.getDamage());
}

void attackPlayer(Player& player, Monster& m){
	player.reduceHealth(m.getDamage());
	fprintf(stdout, "The %s hit you for %d damage\n", m.getName().c_str(),
			m.getDamage());
}

void fightMonster(Player& player){
	Monster m = Monster::getRandomMonster();
	fprintf(stdout, "You have encountered a %s" 
		"\t[Damage: %d\tHealth: %d\tGold: %d]\n",
		m.getName().c_str(), m.getDamage(), m.getHealth(), m.getGold());

	while(true){	
		char response;
		cout << "(r)un or (f)ight: ";
		cin >> response;

		if(response == 'f'){
			attackMonster(player, m);
			
			if(m.isDead()){
				fprintf(stdout, "You killed the %s.\n", m.getName().c_str());
				player.leveUp();
				player.addGold(m.getGold());
				player.printStats();
				break;
			}
			else if(!m.isDead()){
				attackPlayer(player, m);
				if(player.isDead()){
					break;
				}
			}
		}

		else if(response == 'r'){
			int flee = getRandomNumber(0, 1);
			if(flee == 0){
				attackPlayer(player, m);
				if(player.isDead()){
					break;
				}
			}
			else if(flee == 1){
				cout << "You successfully fleed\n";
				player.printStats();
				break;
			}
		}
	}
}

int main(int argc, char const *argv[]){
	srand(static_cast<unsigned int>(time(0)));
	rand();

	string name;
	cout << "Enter your name: \n";
	cin >> name;
	cout << "Welcome, " << name << endl;

	Player player{name};

	while(!player.hasWon() && !player.isDead()){
		fightMonster(player);
	}

	if(player.isDead()){
		fprintf(stdout, "\nYou died at level %d and with %d gold\n", player.getLevel(),
		player.getGold());
		cout << "Too bad you can't take it with you!\n";
	}

	else if(player.hasWon()){
		fprintf(stdout, "Congrats %s!!!\nYou won Monsterous game. Your final gold"
		" collection is %d golds\n", player.getName().c_str(), player.getGold());
	}
 
	return 0;
}