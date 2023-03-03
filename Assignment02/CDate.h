#include<iostream>

using namespace std;

class CDate
{
    int _CDate;
    int _month;
    int _year;

public:
    CDate(): _CDate(1), _month(1), _year(2023){}

    bool isLeapYear();

    constexpr CDate(int CDate, int month, int year):_CDate(CDate), _month(month), _year(year){}

    int dayInMonth();

    friend ostream& operator<< (ostream& outDevice, const CDate& d);
    friend istream& operator>> (istream& inDevice, CDate& d);

    void set(int CDate, int month, int year);

    CDate searchTomorrow();
    CDate searchYesterday();

    int compare(const CDate other);

    int caculateNumOfDayBetween2Moment(const CDate other);
};
