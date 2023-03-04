#include"CDate.h"

bool Date::isLeapYear()
{
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;

    return false;
}

ostream& operator<< (ostream& outDevice, const Date& d)
{
    outDevice << d.date << "/" << d.month << "/" << d.year << endl;

    return outDevice;
}
istream& operator>> (istream& inDevice, Date& d)
{
    cout << "Enter Date, month and year (dd/mm/yy): ";

    char slash = '/';

    inDevice >> d.date >> slash >> d.month >> slash >> d.year;

    return inDevice;
}

void Date::set(int Date, int month, int year)
{
    date = Date;
    month = month;
    year = year;
}

int Date::dayInMonth()
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if(month == 2 && isLeapYear())
        return 29;
    else if(month == 2 && !isLeapYear())
        return 28;
    else return 30;
}

Date Date::Tomorrow()
{
    if(date >= dayInMonth())
    {
        Date nextDay(1, month + 1, year);
        
        if(month > 12)
        {
            nextDay.set(1, 1, nextDay.year + 1);
            return nextDay;
        }

        return nextDay;
    }
    
    return Date(date + 1, month, year);
}

Date Date::Yesterday()
{
    if(date <= 1)
    {
        Date previousDay(30, month - 1, year);

        if(month < 1)
        {
            previousDay.set(30, 12, year - 1);
        }

        return previousDay;
    }

    return Date(date - 1, month, year);
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

    // if(flag == 1)
    //     cout << "Better";
    // else if(flag == -1)
    //     cout << "Lower";
    // else    
    //     cout << "Equal";

    return flag;
}

int Date::calcNumOfDayBetween2Moment(const Date other)
{
    Date temp = *this;

    int day = 0;

    while(this->compare(other) != 0)
    {
        if(this->compare(other) < 0)
            *this = Tomorrow();
        else *this = Yesterday();
        
        day++;
    }

    *this = temp;

    return day;
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