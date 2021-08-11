#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <string>
using namespace std;

//===========================================TASK 1================================================

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 0, int m = 0, int y = 0)
    {
        setDate(d, m, y);
    }

    ~Date() {}

    int getDay() const { return day; }

    int getMonth() const { return month; }

    int getYear() const { return year; }

    void setDay(int day)
    {
        this->day = day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    void setDate(int day, int month, int year)
    {
            setDay(day);
            setMonth(month);
            setYear(year);
    }

    void print() const {
        cout << day << '.'<< month << '.'<< year << std::endl;
    }
};

ostream& operator<< (ostream& os, Date d1)
{
    os << "(DD:MM:YY): " << d1.getDay() << ":" << d1.getMonth() << ":" << d1.getYear() << endl;
    return os;
}

//===========================================TASK 2================================================

void comp(unique_ptr<Date>& d1, unique_ptr<Date>& d2)
{
    if (d1->getYear() > d2->getYear())
        cout << *d1 << " - date is later" << endl;
    else if (d1->getYear() < d2->getYear())
        cout << *d2 << " - date is later" << endl;
    else if (d1->getYear() || d2->getYear())
    {
        if (d1->getMonth() > d2->getMonth())
            cout << *d1 << " - date is later" << endl;
        else if (d1->getMonth() < d2->getMonth())
            cout << *d2 << " - date is later" << endl;
        else if (d1->getMonth() || d2->getMonth())
        {
            if (d1->getDay() > d2->getDay())
                cout << *d1 << " - date is later" << endl;
            else if (d1->getDay() < d2->getDay())
                cout << *d2 << " - date is later" << endl;
            else cout << "These dates are equal to" << endl;
        }
    }
}

void printII()
{
    cout << "-----------------------" << endl;

}

int main()
{
//===========================================TASK 1================================================
    cout << "   TASK 1:" << endl;

    unique_ptr<Date> today(new Date);

    time_t now = time(0);
    tm* t1 = localtime(&now);
    today->setDay(t1->tm_mday);
    today->setMonth(t1->tm_mon + 1);
    today->setYear(t1->tm_year + 1900);
    printII();
    unique_ptr<Date> date = move(today);

    cout << "   Today: ";
    if (today == nullptr)
        cout << "Today is null" << endl;
    else cout << *today;
    printII();
    cout << "   Date: ";
    if (date == nullptr)
        cout << "Date is null" << endl;
    else cout << *date;
    printII();
    cout << endl;

//===========================================TASK 2================================================
    cout << "   TASK 2:" << endl;
    printII();
    unique_ptr<Date> date1(new Date{ 21, 5, 1980 });
    unique_ptr<Date> date2(new Date{ 14, 9, 2014 });
    printII();
    comp(date1, date2);


    return 0;

}