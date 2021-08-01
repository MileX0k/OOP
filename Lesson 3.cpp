#include <iostream>
using namespace std;
#include <string>
#include <locale.h>

//===========================================TASK 1================================================

class Figure {
public:
	virtual void area() {};
};

class Parallelogram : Figure
{
public:
	Parallelogram() {};

	void area()
	{
		cout << "Parallelogram: S = a*h" << endl;
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle() {};

	void area()
	{
		cout << "Rectangle: S = a*b" << endl;
	}

};

class Square : public Parallelogram
{
public:
	Square() {};

	void area()
	{
		cout << "Square: S = a^2" << endl;
	}

};

class Rhombus : public Parallelogram
{
public:
	Rhombus() {};

	void area()
	{
		cout << "Rhombus: S = 1/2 * (d1 * d2)" << endl;
	}

};

class Circle : Figure
{
public:
	Circle() {};

	void area()
	{
		cout << "Circle: S = PR^2" << endl;
	}
};

//===========================================TASK 2================================================

class Car 
{
private:
	string company = "__";
	string model = "_";

public:

	Car() {};

	Car(string comp, string mod)
		: company(comp), model(mod)
	{
		cout << "------------------" << endl;
		cout << "Car company: " << company << endl;
		cout << "Car model: " << model << endl;
	};

	void print() {
		cout << "Car company: " << company << endl;
		cout << "Car model: " << model << endl;
	}

};

class PassengerCar : virtual public Car
{
private:
	int age = 0;

public:

		PassengerCar() {};

		PassengerCar(string comp, string mod, int a)
		:Car(comp, mod)	{
			age = a;
			cout << "Car age: " << age << endl;

		};
};

class Bus : virtual public Car
{
private:
	string bodyType;

public:
	Bus() {};

	Bus(string comp, string mod, string bt)
		:Car(comp, mod) , bodyType(bt)
	{
		cout << "Body type: " << bodyType << endl;
	};
};

class Minivan : public PassengerCar, Bus
{
public:

	Minivan() {};

	Minivan(string comp, string mod)
		:Car(comp, mod)
	{};
};

//===========================================TASK 3================================================

class Fraction
{
private: 
	float numerator = 0;
	float denominator = 1;
	float value = 0;

public:
	Fraction() {};

	Fraction(float num, float den)
	:numerator(num), denominator(den)
	{
		if (den == 0) cout << "ERROR! denominator = 0!" << endl;
		else
		{
			value = numerator / denominator;
			cout << "Fraction:" << numerator << "/" << denominator << " = " << value << endl;
		}
	}

	Fraction operator-() const
	{
		cout << "Unar " << value << " = " << -value << endl;
		return Fraction();
	};



	friend const Fraction& operator+ (const Fraction& f1, const Fraction& f2);
	friend const Fraction& operator- (const Fraction& f1, const Fraction& f2);
	friend const Fraction& operator* (const Fraction& f1, const Fraction& f2);
	friend const Fraction& operator/ (const Fraction& f1, const Fraction& f2);

	friend const Fraction& operator== (const Fraction& f1, const Fraction& f2);
	friend const Fraction& operator!= (const Fraction& f1, const Fraction& f2);
	friend const Fraction& operator< (const Fraction& f1, const Fraction& f2);
	friend const Fraction& operator> (const Fraction& f1, const Fraction& f2);

	float getFraction() { return value; }

};

const Fraction& operator+ (const Fraction& f1, const Fraction& f2)
{
	float sum = f1.value + f2.value;
	cout << "Sum: " << f1.value << " + " << f2.value << " = " << sum << endl;
	return f1;
}

const Fraction& operator- (const Fraction& f1, const Fraction& f2)
{
	float diff = f1.value - f2.value;
	cout << "Difference: " << f1.value << " - " << f2.value << " = " << diff << endl;
	return f1;
}

const Fraction& operator* (const Fraction& f1, const Fraction& f2)
{
	float mul = f1.value * f2.value;
	cout << "Multiplication: " << f1.value << " * " << f2.value << " = " << mul << endl;
	return f1;
}

const Fraction& operator/ (const Fraction& f1, const Fraction& f2)
{
	float div = f1.value / f2.value;
	cout << "Division: " << f1.value << " / " << f2.value << " = " << div << endl;
	return f1;
}



const Fraction& operator==(const Fraction& f1, const Fraction& f2)
{
	if (f1.value == f2.value)
	{
		cout << "Equality:  " << f1.value << " == " << f2.value << endl;
	}
	else
	{
		cout << "Equality:  " << f1.value << " != " << f2.value << endl;
	}

	return f1;
}

const Fraction& operator!=(const Fraction& f1, const Fraction& f2)
{
	Fraction eq22 = f1 == f2;
	return f1;
}

const Fraction& operator<(const Fraction& f1, const Fraction& f2)
{
	if (f1.value < f2.value)
	{
		cout << "Compare:  " << f1.value << " < " << f2.value << endl;
	}
	else
	{
		cout << "Compare:  " << f1.value << " >= " << f2.value << endl;
	}

	return f1;
}

const Fraction& operator>=(const Fraction& f1, const Fraction& f2)
{
	Fraction com22 = f1 < f2;
	return f1;
}

const Fraction& operator>(const Fraction& f1, const Fraction& f2)
{
	if (f1.value > f2.value)
	{
		cout << "Compare:  " << f1.value << " > " << f2.value << endl;
	}
	else
	{
		cout << "Compare:  " << f1.value << " <= " << f2.value << endl;
	}

	return f1;
}

const Fraction& operator<=(const Fraction& f1, const Fraction& f2)
{
	Fraction com22 = f1 > f2;
	return f1;
}


//===========================================TASK 4================================================

class Card
{
private:
	enum suit_card { spades, hearts, crosses, booby };
	enum value_card { ace = 1, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, picture = 10};
	bool position_card = 0;
public:

	Card() {};


	bool Flip() {
		if (position_card == 0) return false;
		else return true;
	};

	int getValue() { return Card::value_card::ace; };

};

int main()
{
	
//===========================================TASK 1================================================
	
	cout << "    TASK 1:    " << endl;

	Circle c1{};
	Rhombus r1{};
	Square s1{};
	c1.area();
	r1.area();
	s1.area();

	cout << endl;

//===========================================TASK 2================================================

	cout << "    TASK 2:    " << endl;

	Minivan m1{ "Toyota" , "Sienna III 2010" };
	PassengerCar pc{"Mazda" , "6", 2015 };
	setlocale(LC_ALL, "Russian");
	Bus b1{ "ЛиАЗ" , "621322" , "bonnetless" };

	cout << endl;

//===========================================TASK 3================================================

	cout << "    TASK 3:    " << endl;

	Fraction f1{ 3, 0};
	
	Fraction f2{ 5, 8 };
	Fraction f3{ 9, 24 };
	Fraction f4{ 0, 2 };
	Fraction f5{ 15, 24 };
	cout << "------------------" << endl;
	Fraction fsum = f2 + f3;
	Fraction fdiff = f3 - f2;
	Fraction fmul = f2 * f3;
	Fraction fdiv = f3 / f2;
	cout << "------------------" << endl;
	Fraction funar = -f3;
	cout << "------------------" << endl;
	Fraction feq1 = f2 == f5;
	Fraction feq2 = f2 != f3;
	Fraction fcom = f4 < f3;
	Fraction fcom3 = f2 >= f4;
	Fraction fcom2 = f3 > f2;
	Fraction fcom4 = f5 <= f3;

	//===========================================TASK 4================================================
	cout << "    TASK 4:    " << endl;

	Card re{};
	cout << re.getValue() << endl;

	return 0;
}
