#include"Date.h"

bool isLeapYear(const int _year)
{
    if(_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
        return true;

    return false;
}

ostream& operator<< (ostream& outDevice, const Date& d)
{
    outDevice << d.date << "/" << d.month << "/" << d.year;

    return outDevice;
}
istream& operator>> (istream& inDevice, Date& d)
{
    cout << "Enter date, month and year (dd/mm/yy): ";

    char slash = '/';

    inDevice >> d.date >> slash >> d.month >> slash >> d.year;

    return inDevice;
}

void Date::set(int _year, int _month, int _date)
{
    date = _date;
    month = _month;
    year = _year;
}

int dayInMonth(const int _month, const int _year)
{
    if(_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
        return 31;
    else if(_month == 2 && isLeapYear(_year))
        return 29;
    else if(_month == 2 && isLeapYear(_year))
        return 28;
    else return 30;
}

Date Date::Tomorrow()
{
    if(date >= dayInMonth(month, year))
    {
        Date nextDay(year, month + 1, 1);
        
        if(nextDay.month > 12)
        {
            nextDay.set(nextDay.year + 1, 1, 1);
            return nextDay;
        }

        return nextDay;
    }
    
    return Date(year, month, date + 1);
}

Date Date::Yesterday()
{
    if(date <= 1)
    {
        Date previousDay(year,  month - 1, dayInMonth(month, year));

        if(previousDay.month < 1)
        {
            previousDay.set(year - 1, 12, 31);
        }

        return previousDay;
    }

    return Date(year, month, date - 1);
}

int Date::compare(const Date other)
{
    int flag;

    if(year > other.year)
        flag = 1;
    else if(year < other.year)
        flag = -1;
    else{
        if(month > other.month)
            flag = 1;
        else if(month < other.month)
            flag = -1;
        else{
            if(date > other.date)
                flag = 1;
            else if(date < other.date)
                flag = -1;
            else flag = 0;
        }
    }

    return flag;
}

int Date::calcNumOfDayBetween2Moment(const Date other)
{
    long int n1 = date + 365 * year;

    for(int i = 1; i < month; i++)
        n1 += dayInMonth(i, year);
    
    for(int i = 1; i < year; i++)
        n1 += isLeapYear(i);


    long int n2 = other.date + 365 * other.year;

    for(int i = 1; i < other.month; i++)
        n2 += dayInMonth(i, other.year);
    
    for(int i = 1; i < other.year; i++)
        n2 += isLeapYear(i);

    return n2 - n1;
}

bool Date::operator==(const Date& other)
{
    return (date == other.date && month == other.month && year == other.year);
}

bool Date::operator!=(const Date& other)
{
    return (date != other.date || month != other.month || year != other.year);

}

bool Date::operator>=(const Date& other)
{
    return compare(other) >= 0;
}

bool Date::operator<=(const Date& other)
{
    return compare(other) <= 0;
}

bool Date::operator>(const Date& other)
{
    return compare(other) > 0;
}

bool Date::operator<(const Date& other)
{
    return compare(other) < 0;
}

Date Date::operator+(int num)
{
    Date result = *this;

    while (num--)
        result = result.Tomorrow();

    return result;
}

Date& Date::operator+=(int num)
{
    return *this = *this + num;
}

Date Date::operator-(int num)
{
    Date result = *this;

    while (num--)
        result = result.Yesterday();

    return result;
}

Date& Date::operator-=(int num)
{
    return *this = *this + num;
}

Date Date::operator++(int num)
{
    Date result = *this;

    *this = *this + 1;

    return result;
}

Date& Date::operator++()
{
    return *this = *this + 1;
}

Date Date::operator--(int num)
{
    Date result = *this;

    *this = *this - 1;

    return result;
}

Date Date::operator--()
{
    return *this = *this - 1;
}

Date::operator int() const
{
    return Date(year, 1, 1).calcNumOfDayBetween2Moment(*this);
}

Date::operator long() const
{
    return Date(1, 1, 1).calcNumOfDayBetween2Moment(*this);
}