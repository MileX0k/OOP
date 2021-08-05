#include <iostream>
#include <vector>
using namespace std;

class Card
{
public:

	enum rank_card { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
	enum suit_card { SPADES, HEARTS, CROSSES, BOBBY };

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
	friend ostream& operator<<(ostream& os, const Card& aCard);
private:
	suit_card m_Suit;
	rank_card m_Rank;
	bool position_card;
};

class Hand
{
protected:
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

	int getTotal() const {
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

class GenericPlayer : public Hand
{
protected:
	string name{};

public:

	GenericPlayer(const string& n = "") 
	:name(n) {};

	~GenericPlayer() {};

	virtual bool IsHitting()  const = 0 ;

	bool IsBoosted() const {
		return (getTotal() > 21);
	}

	void Bust()
	{
		if (IsBoosted)
			cout << name << " has too much point";
	}

	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

};

class Player : public GenericPlayer
{
public:
	Player(const string& n = "") :GenericPlayer(n) {};

	~Player() {};

	bool IsHitting() const {
		cout << name << ", do you want a hit? (Y/N): ";
		char response;
		cin >> response;
		return (response == 'y' || response == 'Y');
	}

	void Win() const { cout << name << " wins!\n"; }

	void Lose() const { cout << name << " loses!\n"; }

	void Push() const { cout << name << " pushes!\n"; }

};

class House : public GenericPlayer
{
	House(const string& n = "House");

	bool IsHiitting() const { return (getTotal() <= 16); }

	void FlipFirstCard() {
		if (!(hand.empty()))
			hand[0]->Flip();
		else
			cout << "No card to flip!\n";
	}
};

ostream& operator<<(ostream& os, const Card& aCard)
{
	const string RANK_CARD[] = { "0", "A", "2", "3", "4", "5","6", "7", "8", "9", "10", "J", "Q", "K" };
	const string SUIT_CARD[] = { "s", "h", "c", "b" };

	if (aCard.position_card)
		os << RANK_CARD[aCard.m_Rank] << SUIT_CARD[aCard.m_Suit];
	else
		os << "XX";

	return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.name << ":\t";

	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.hand.empty())
	{
		for (pCard = aGenericPlayer.hand.begin();
			pCard != aGenericPlayer.hand.end();
			++pCard)
		{
			os << *(*pCard) << "\t";
		}

		if (aGenericPlayer.getTotal() != 0)
		{
			cout << "(" << aGenericPlayer.getTotal() << ")";
		}
	}
	else
	{
		os << "<empty>";
	}
	return os;
}


int main()
{
	cout << "\t\tWelcome to Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? (1 - 7): ";
		cin >> numPlayers;
	}

	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;

	// игровой цикл
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}

	return 0;
}

