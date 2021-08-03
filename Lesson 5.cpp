#include <iostream>
using namespace std;

//===========================================TASK 1================================================

template <class P>
class Pair1
{
private:
    P first;
    P second;

public:

    Pair1(P f, P s)
        :first(f), second(s)
    {}

    P getFirst() const { return first; }

    P getSecond() const { return second; }

};

//===========================================TASK 2================================================


template <typename Pf, typename Ps >
class Pair
{
private:
    Pf first;
    Ps second;

public:

    Pair(Pf f, Ps s)
        :first(f), second(s)
    {}

    Pf getFirst() const { return first; }

    Ps getSecond() const { return second; }

};

//===========================================TASK 3================================================

template <typename T>
class StringValuePair : public Pair<string, T>
{
private:
    string first{};
    T second{};

public:

    StringValuePair(string f, T s)
        :Pair<string, T>(f,s)
    {}

};


int main()
{
//===========================================TASK 1================================================
    cout << "   TASK 1   " << endl;
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.getFirst() << " " << p1.getSecond() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.getFirst() << " " << p2.getSecond() << '\n';

    cout << endl;

//===========================================TASK 2================================================
    cout << "   TASK 2   " << endl;

    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.getFirst() << ' ' << p3.getSecond() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.getFirst() << ' ' << p4.getSecond() << '\n';

    cout << endl;

//===========================================TASK 3================================================
    cout << "   TASK 3   " << endl;

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.getFirst() << ' ' << svp.getSecond() << '\n';

    cout << endl;
    return 0;
}
