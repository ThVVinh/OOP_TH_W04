#include"CDate.h"

bool CDate::isLeapYear()
{
    if(_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
        return true;

    return false;
}

ostream& operator<< (ostream& outDevice, const CDate& d)
{
    outDevice << d._CDate << "/" << d._month << "/" << d._year << endl;

    return outDevice;
}
istream& operator>> (istream& inDevice, CDate& d)
{
    cout << "Enter CDate, month and year (dd/mm/yy): ";

    char slash = '/';

    inDevice >> d._CDate >> slash >> d._month >> slash >> d._year;

    return inDevice;
}

void CDate::set(int CDate, int month, int year)
{
    _CDate = CDate;
    _month = month;
    _year = year;
}

int CDate::dayInMonth()
{
    if(_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
        return 31;
    else if(_month == 2 && isLeapYear())
        return 29;
    else if(_month == 2 && !isLeapYear())
        return 28;
    else return 30;
}

CDate CDate::searchTomorrow()
{
    if(_CDate >= dayInMonth())
    {
        CDate nextDay(1, _month + 1, _year);
        
        if(_month > 12)
        {
            nextDay.set(1, 1, nextDay._year + 1);
            return nextDay;
        }

        return nextDay;
    }
    
    return CDate(_CDate + 1, _month, _year);
}

CDate CDate::searchYesterday()
{
    if(_CDate <= 1)
    {
        CDate previousDay(30, _month - 1, _year);

        if(_month < 1)
        {
            previousDay.set(30, 12, _year - 1);
        }

        return previousDay;
    }

    return CDate(_CDate - 1, _month, _year);
}

int CDate::compare(const CDate other)
{
    int flag;

    if(_year > other._year)
        flag = 1;
    else if(_year < other._year)
        flag = -1;
    else{
        if(_month > other._month)
            flag = 1;
        else if(_month < other._month)
            flag = -1;
        else{
            if(_CDate > other._CDate)
                flag = 1;
            else if(_CDate < other._CDate)
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

int CDate::caculateNumOfDayBetween2Moment(const CDate other)
{
    CDate temp = *this;

    int day = 0;

    while(this->compare(other) != 0)
    {
        if(this->compare(other) < 0)
            *this = searchTomorrow();
        else *this = searchYesterday();
        
        day++;
    }

    *this = temp;

    return day;
}