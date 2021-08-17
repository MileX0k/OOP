#include <iostream>
using namespace std;

//===========================================TASK 1================================================
template <typename T>
void fer(T a, T b)
{
	try
	{
		if (b == 0)
			throw  "DivisionByZero";
		else
		{
			T res = a / b;
			cout << "Result " << a <<  " / " << b <<  "=  " << res << endl;

		}

	}
	catch (const char*)
	{
		cout << "ERROR! Divison by zero" << endl;
	}


}
//===========================================TASK 2================================================

class Ex
{
private:
	int x;

public:

	Ex(int m_x) 
	:x(m_x)
	{}
};

class Bar
{
private:
	int y;

public:

	Bar(int m_y = 0)
		:y(m_y)
	{}

	void setBar(int a) {
		if (y + a > 100)
			throw Ex(a * y);
		else y = a;
	}

	int getBar() { return y; }
};

//===========================================TASK 3================================================

class Robot
{
private:
	const int SIZE = 10;
	int m_x = 0;
	int m_y = 0;
	char** field = new char* [SIZE];

protected:
	bool game = true;

public:

	Robot() {
		for (size_t i = 0; i < SIZE; i++)
		{
			field[i] = new char[SIZE];
		}

		for (size_t i = 0; i < SIZE; i++)
		{
			for (size_t j = 0; j < SIZE; j++)
			{
				field[i][j] = '_';
			}
		}


	}

	void Move(char move) {
		if (move == 'a' || move == 'A' ||
			move == 'd' || move == 'D' ||
			move == 'w' || move == 'W' ||
			move == 's' || move == 'S')
		{

			if (move == 'a' || move == 'A')
			{
				if (m_y == 0)
					throw "ERROR! Off the field (left)!";
				else m_y--;
			}

			if (move == 'd' || move == 'D')
			{
				if (m_y == 9)
					throw "ERROR! Off the field (right)!";
				else m_y++;
			}
			if (move == 'w' || move == 'W')
			{
				if (m_x == 0)
					throw "ERROR! Off the field (top)!";
				else m_x--;
			}

			if (move == 's' || move == 'S')
			{
				if (m_x == 9)
					throw "ERROR! Off the field (bot)!";
				else m_x++;
			}


		}
		else throw "ERROR! Illegal command!";
	}

	void ClearRobot() {
		field[m_x][m_y] = '_';
	}

	void printField() {
		
		for (size_t i = 0; i < SIZE; i++)
		{
			for (size_t j = 0; j < SIZE; j++)
			{
				field[m_x][m_y] = '*';
				cout << field[i][j] << "| ";
			}
			cout << endl;
		}
		ClearRobot();
	}

	bool Again(char ep) {
		if (ep == 'y' || ep == 'Y' || ep == 'n' || ep == 'N')
		{
			if (ep == 'y' || ep == 'Y')
			{
				return game;
			}
			else if (ep == 'n' || ep == 'N') {
				game = false;
				return game;
			}
		}
		else
		{
			throw "ERROR! Illegal command!";
		}
	}

	void ClearField() {
		system("cls");
	}

	bool Game()	{
		if (game)
			return true;
		else return false;
	}

	~Robot() {
		for (size_t i = 0; i < SIZE; i++)
		{
			delete [] field[i];
		}
		delete[] field;
	}

};

int main()
{
//===========================================TASK 1================================================
	cout << "   TASK 1:" << endl;

	fer(14, 0);
	fer(5.6, 3.0);
	fer(83, 12);

	cout << endl;
//===========================================TASK 2================================================
	cout << "   TASK 2:" << endl;

	Bar bar{};

	do
	{
		try
		{
		int n;
		cout << "Enter your number: ";
		cin >> n;
		bar.setBar(n);
		}
		catch (const Ex&)
		{
			cout << "Error! Value > 100 "<< endl;
		}
	} while (bar.getBar() != 0);

//===========================================TASK 3================================================
	cout << "   TASK 3:" << endl;

	Robot r1;
	do
	{
		try {


			try
			{
				r1.ClearField();
				r1.printField();
				char foo;
				cout << "Move. ('w','a','s','d')";
				cin >> foo;
				r1.Move(foo);
			}
			catch (const char* error)
			{
				cout << "STOP! " << error << endl << "Again?";
				char pe; 
				cout << "(y / n)";
				cin >> pe;
				r1.Again(pe);
			}
		}
		catch (const char* error)
		{
			cout << "STOP! " << error << endl;
			char te;
			cout << "(y / n)";
			cin >> te;
			r1.Again(te);
		}

	} while (r1.Game());


}
