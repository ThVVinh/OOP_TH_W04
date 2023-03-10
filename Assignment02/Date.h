#include<iostream>

using namespace std;

class Date
{
    int date;
    int month;
    int year;

public:
    Date(): date(2), month(11), year(2012){}
    Date(int _year): year(_year), month(1), date(1){}
    Date(int _year, int _month): year(_year), month(_month), date(1){}
    Date(int _year, int _month, int _date): year(_year), month(_month), date(_date){}
    Date(const Date& other):date(other.date), month(other.month), year(other.year){}

    friend bool isLeapYear(const int _year);

    friend int dayInMonth(const int _month, const int _year);

    friend ostream& operator<< (ostream& outDevice, const Date& d);
    friend istream& operator>> (istream& inDevice, Date& d);
    
    bool operator==(const Date& other);
    bool operator!=(const Date& other);
    bool operator>=(const Date& other);
    bool operator<=(const Date& other);
    bool operator>(const Date& other);
    bool operator<(const Date& other);

    Date operator+(int num);
    Date& operator+=(int num);
    Date operator-(int num);
    Date& operator-=(int num);

    Date operator++(int num);
    Date& operator++();

    Date operator--(int num);
    Date operator--();

    operator int() const;
    operator long() const;


    void set(int _year, int _month, int _day);

    Date Tomorrow();
    Date Yesterday();

    int compare(const Date other);

    int calcNumOfDayBetween2Moment(const Date other);
};