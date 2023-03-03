#include<iostream>
#include<string.h>
#include<sstream>
using std::cout;
using std::cin;
using std::endl;

class Fraction
{
    private:
        int numerator;
        int denominator;

    public:
        Fraction();
        Fraction(int _numerator, int _denominator);
        Fraction(const Fraction& other);
        ~Fraction();

        int FindGcd();

        Fraction& Reduce();
        
        //Add 2 fractions
        Fraction operator+(const Fraction& other);

        //Substract 2 fractions
        Fraction operator-(const Fraction& other);

        //Multiply 2 fractions
        Fraction operator*(const Fraction& other);

        //Divide 2 fractions. throw; if divided by zero
        Fraction operator/(const Fraction& other);

        Fraction &operator=(const Fraction& other);

        Fraction& operator+=(const Fraction& other);

        Fraction& operator-=(const Fraction& other);

        Fraction& operator*=(const Fraction& other);

        Fraction& operator/=(const Fraction& other);

        bool operator>(const Fraction& other);

        bool operator<(const Fraction& other);

        bool operator==(const Fraction& other);

        bool operator>=(const Fraction& other);

        bool operator<=(const Fraction& other);

        bool operator!=(const Fraction& other);

        Fraction& operator++();

        Fraction operator++(int num);

        Fraction& operator--();

        Fraction operator--(int num);

        Fraction operator+(int num);

        Fraction operator-(int num);

        friend Fraction operator+(int num, const Fraction& frac);
        friend Fraction operator*(int num, const Fraction& frac);

        operator float() const;

        operator int() const;

        //Input
        friend std::ostream& operator<< (std::ostream& outDevice, const Fraction& frac);
        
        //Output
        friend std::istream& operator>> (std::istream& inDevice, Fraction& frac);
};
