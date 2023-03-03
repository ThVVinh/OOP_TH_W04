#include<iostream>

using namespace std;

class Date
{
    int date;
    int month;
    int year;

public:
    Date(): date(1), month(1), year(2023){}
    constexpr Date(int _date, int _month, int _year):date(_date), month(_month), year(_year){}
    Date(int _year);
    Date(int _year, int _month): year(_year), month(_month){}
    Date(int _year, int _month, int _date): year(_year), month(_month), date(_date){}
    Date(const Date& other){date = other.date; month = other.month; year = other.year;}

    bool isLeapYear();

    int dayInMonth();

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
    Date operator++();

    Date operator--(int num);
    Date operator--();

    operator int() const;
    operator long() const;


    void set(int Date, int month, int year);

    Date Tomorrow();
    Date Yesterday();

    int compare(const Date other);

    int caculateNumOfDayBetween2Moment(const Date other);
};
