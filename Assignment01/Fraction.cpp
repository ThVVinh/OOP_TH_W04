#include"Fraction.h"

Fraction::Fraction(): numerator(0), denominator(1)
{

}

Fraction::Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator)
{

}

Fraction::Fraction(const Fraction& other)
{
    numerator = other.numerator;
    denominator = other.denominator;
}

Fraction::~Fraction()
{
    cout << "Call Destructor of " << *this << endl; 
}


std::ostream& operator<< (std::ostream& outDevice, const Fraction& frac)
{
    if(frac.denominator < 0)
        outDevice << (-1 * frac.numerator) << "/" << (-1* frac.denominator);
    else outDevice << frac.numerator << "/" << frac.denominator;

    return outDevice;
}
std::istream& operator>> (std::istream& inDevice,  Fraction& frac)
{
    cout << "Enter fraction (a/b): ";

    char c = '/';

    inDevice >> frac.numerator >> c >> frac.denominator;

    return inDevice;
}

int Fraction::FindGcd()
{
    if (numerator == 0 || denominator == 0)
    {
        return 1;
    }

    int _numerator = abs(numerator);
    int _denominator = abs(denominator);

    while (_numerator != _denominator)
    {
        if (_numerator > _denominator)
            _numerator -= _denominator;
        else _denominator -= _numerator;
    }

    return _numerator;
}

Fraction& Fraction::Reduce()
{
    int Gcd = FindGcd();

    numerator /= Gcd;
    denominator /= Gcd; 

    return *this;
}


Fraction Fraction::operator+(const Fraction& other)
{
    Fraction result;

    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;

    result.Reduce();

    return result;
}

Fraction Fraction::operator-(const Fraction& other)
{
    Fraction result;

    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;

    result = result.Reduce();

    return result;
}

Fraction Fraction::operator+(int num)
{
    Fraction result;

    result = *this + Fraction(num, 1);

    return result;
}

Fraction Fraction::operator-(int num)
{
    Fraction result;

    result = *this - Fraction(num, 1);

    return result;
}

Fraction operator+(int num, const Fraction& frac)
{
    Fraction result;

    result = Fraction(num, 1) + frac;

    return result;
}

Fraction operator*(int num, const Fraction& frac)
{
    Fraction result;

    result = Fraction(num, 1) * frac;

    return result;
}

Fraction Fraction::operator*(const Fraction& other)
{
    Fraction result;

    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;

    result = result.Reduce();

    return result;
}

Fraction Fraction::operator/(const Fraction& other)
{
    Fraction result;

    if(other.denominator == 0 || other.numerator == 0)
    {
        cout << "Devided by 0" << endl;
        return result;
    }

    result.numerator = numerator * other.denominator;
    result.denominator = denominator * other.numerator;

    result = result.Reduce();

    return result;
}

Fraction &Fraction::operator=(const Fraction& other)
{
    numerator = other.numerator;
    denominator = other.denominator;

    return *this;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
    *this = *this + other;

    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
    *this = *this - other;

    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
    *this = *this * other;

    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
    *this = *this / other;

    return *this;
}
bool Fraction::operator>(const Fraction& other)
{
    return (1.0 * numerator / denominator) > (1.0 * other.numerator / other.denominator);
}

bool Fraction::operator<(const Fraction& other)
{
    return (1.0 * numerator / denominator) < (1.0 * other.numerator / other.denominator);
}

bool Fraction::operator==(const Fraction& other)
{
    return (1.0 * numerator / denominator) == (1.0 * other.numerator / other.denominator);
}

bool Fraction::operator>=(const Fraction& other)
{
    return (1.0 * numerator / denominator) >= (1.0 * other.numerator / other.denominator);
}

bool Fraction::operator<=(const Fraction& other)
{
    return (1.0 * numerator / denominator) <= (1.0 * other.numerator / other.denominator);
}

bool Fraction::operator!=(const Fraction& other)
{
    return (1.0 * numerator / denominator) != (1.0 * other.numerator / other.denominator);
}

Fraction& Fraction::operator++()
{
    *this = *this + Fraction(1, 1);

    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction result = *this;

    *this = *this + Fraction(1,1);

    return result;
}

Fraction& Fraction::operator--()
{
    *this = *this - Fraction(1, 1);

    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction result = *this;

    *this = *this - Fraction(1,1);

    return result;
}

Fraction::operator float() const
{
    return 1.0 * numerator / denominator;
}

Fraction::operator int() const
{
    return numerator / denominator;
}