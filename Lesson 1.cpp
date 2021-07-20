#include <iostream>
#include <cstdint>
#include <stdint.h>
using namespace std;

//===========================================TASK 1================================================
class Power
{
private:
	int one = 4;
	int two = 5;
	
public:
	void setPower() {};

	void calculate()
	{
		int res = 1;
		if (two < 0)
			res = -1;
		else if (two == 0)
			res = 1;
		else 
		{
			for (size_t i = 0; i < two; i++)
			{
				res *= one;
			}
		}
		if (res == -1)
			cout << "Error, degree < 0!" << endl;
		cout << "Result: " << res << endl;

	}
};
//===========================================TASK 2================================================

class RGBA
{
private:
	uint8_t m_red = 0;
	uint8_t m_green = 0;
	uint8_t m_blue = 0;
	uint8_t m_alpha = 255;
public:

	RGBA() {};

	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
		:m_red (red), m_green (green), m_blue (blue), m_alpha (alpha)
	{

	}

	void print() // Привёл к типу инт, т.к. у меня компилятор не может правильно обработать тип uint8_t
	{
		cout << "Red: " << (int)m_red << endl;
		cout << "Green: " << (int)m_green << endl;
		cout << "Blue: " << (int)m_blue << endl;
		cout << "Alpha: " << (int)m_alpha << endl;
	}

};

//===========================================TASK 3================================================

class Stack
{
private:
	int sizeS = 10;
	int * array;
	int idx = 0;

public:

	void reset()
	{
		idx = 0;
		array = new int [sizeS];
	}

	void push(int num)
	{
		if (idx < sizeS)
		{
			array[idx] = num;
			idx++;
		}
		else cout << "Error! Stack overflow!" << endl;
	}

	void pop()
	{
		if (idx == 0)
			cout << "Error! Stack is empty!" << endl;
		else idx--;
	}


	void print()
	{
		cout << "( ";
		for (int i = 0; i < idx; i++)
		{
			cout << array[i] << " ";
		}
		cout << ")";
		cout << endl;
	}
};

int main()
{
//===========================================TASK 1================================================
	cout << "    TASK 1:    " << endl;
	Power power;
	power.setPower();
	power.calculate();
	cout << endl;

//===========================================TASK 2================================================
	cout << "    TASK 2:    " << endl;
	RGBA color;
	color.print();
	cout << endl;
	RGBA color2(10, 111, 202, 160);
	color2.print();
	cout << endl;

//===========================================TASK 3================================================
	cout << "    TASK 3:    " << endl;
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();


	return 0;

}

