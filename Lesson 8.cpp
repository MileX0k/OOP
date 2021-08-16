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
		catch (const Ex& error)
		{
			cout << "Error! Value > 100 "<< endl;
		}
	} while (bar.getBar() != 0);


}
