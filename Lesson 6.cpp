#include <iostream>
using namespace std;

//===========================================TASK 1================================================
template<class T>
T Task1()
{
	T a;

	cout << "Enter your number: "; 
	cin >> a;

	while (cin.fail() || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(9999, '\n');
		cin.sync();
		cout << "Error! Wrong number!\n\n" << "Enter your number: ";
		cin >> a;
	}
	return a;
}



int main()
{
//===========================================TASK 3================================================	
	cout << "   TASK 1" << endl;

	while (true)
	{
		Task1<int>();
		break;
	}

	cout << endl;



	return 0;
}