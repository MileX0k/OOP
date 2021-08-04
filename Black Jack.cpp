#include <iostream>
#include <vector>
using namespace std;

class Card
{
public:

	enum suit_card { SPADES, HEARTS, CROSSES, BOBBY };
	enum rank_card { ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KINK = 10 };

	Card(rank_card r, suit_card s, bool p)
		:m_Rank(r), m_Suit(s), position_card(p)
	{};

	void Flip() {
		position_card = !(position_card);
	};

	int getValue() const { 
		int value = 0;
		if (position_card)
			value = m_Rank;
		 };

private:
	suit_card m_Suit;
	rank_card m_Rank;
	bool position_card = 0;
};

class Hand
{
private:
	vector <Card*> hand;

public:

	Hand() { hand.reserve(7); }

	~Hand() { Clear(); }

	void Add(Card* new_card) { hand.push_back(new_card); };

	void const Clear() { 
		vector<Card*>::iterator iter = hand.begin();
		for (iter = hand.begin(); iter != hand.end(); ++iter)
		{
			delete* iter;
			*iter = 0;
		}
	
		hand.clear();

	}

	int getTotal() {
		if (hand.empty())
			return 0;
		
		if (hand[0]->getValue() == 0)
			return 0;

		int total = 0;
		vector<Card*>::const_iterator iter;
		for (iter = hand.begin(); iter != hand.end(); ++iter)
		{
			total += (*iter)->getValue();
		}

		bool containsAce = false;
		for (iter = hand.begin(); iter != hand.end(); ++iter)
		{
			if ((*iter)->getValue() == Card::ACE)
			{
				containsAce = true;
			}
		}

		if (containsAce && total <= 11)
		{
			total += 10;
		}

		return total;
	}
};


int main()
{

	return 0;

}

