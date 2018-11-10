#include <iostream>
#include <array>
#include <ctime>

using namespace std;

class Card{
public:
	enum CardSuit{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS,
	};
	enum CardRank{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS,
	};
private:
	CardRank m_rank;
	CardSuit m_suit;
public:
	Card(CardRank rank=RANK_2, CardSuit suit=SUIT_CLUB): m_rank{rank}, m_suit{suit}{};
	void printCard(void)const{
		switch (m_rank){
			case RANK_2:		std::cout << "2 "; break;
			case RANK_3:		std::cout << "3 "; break;
			case RANK_4:		std::cout << "4 "; break;
			case RANK_5:		std::cout << "5 "; break;
			case RANK_6:		std::cout << "6 "; break;
			case RANK_7:		std::cout << "7 "; break;
			case RANK_8:		std::cout << "8 "; break;
			case RANK_9:		std::cout << "9 "; break;
			case RANK_10:		std::cout << "T "; break;
			case RANK_JACK:		std::cout << "J "; break;
			case RANK_QUEEN:	std::cout << "Q "; break;
			case RANK_KING:		std::cout << "K "; break;
			case RANK_ACE:		std::cout << "A "; break;
		}
		switch (m_suit){
			case SUIT_CLUB:		std::cout << "C\n"; break;
			case SUIT_DIAMOND:	std::cout << "D\n"; break;
			case SUIT_HEART:	std::cout << "H\n"; break;
			case SUIT_SPADE:	std::cout << "S\n"; break;
		}
	}
	int getCardValue(void)const{
		switch (m_rank){
			case RANK_2:		return 2;
			case RANK_3:		return 3;
			case RANK_4:		return 4;
			case RANK_5:		return 5;
			case RANK_6:		return 6;
			case RANK_7:		return 7;
			case RANK_8:		return 8;
			case RANK_9:		return 9;
			case RANK_10:		return 10;
			case RANK_JACK:		return 10;
			case RANK_QUEEN:	return 10;
			case RANK_KING:		return 10;
			case RANK_ACE:		return 11;
		}
		return 0;
	}

};

class Deck{
private:
	array<Card, 52> m_deck;
	static int getRandomNumber(int min, int max){
		static const double ratio = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * ratio * (max-min+1) + min);
	}
	static void swapCard(Card& a, Card& b){
		Card temp = a;
		a = b;
		b = temp;
	}
public:
	Deck(){
		int card_index = 0;
		for(int suit_index=0; suit_index<Card::MAX_SUITS; ++suit_index){
			for(int rank_index=0; rank_index<Card::MAX_RANKS; ++rank_index){
				m_deck[card_index] = Card(static_cast<Card::CardRank>(rank_index), 
										  static_cast<Card::CardSuit>(suit_index));
				++card_index;
			}
		}
	};
	void printDeck(void)const{
		for(const auto& card : m_deck){
			card.printCard();
			cout << "\n";
		}
	}
	void shuffleDeck(void){
		for(int index=0; index<52; ++index){
			int swapIndex = getRandomNumber(0, 51);
			swapCard(m_deck[index], m_deck[swapIndex]);
		}
	}	
};

int main(int argc, char const *argv[]){
	const Card cardQueenHearts{Card::RANK_QUEEN, Card::SUIT_HEART};
	cardQueenHearts.printCard();
	cout << "Its value is: " << cardQueenHearts.getCardValue() << endl;

	srand(time(0));
	rand();
	Deck deck;
	deck.printDeck();
	deck.shuffleDeck();
	deck.printDeck();
	return 0;
}
