#include<iostream>
#include<limits.h>

using std::cout;
using std::cin;
using std::endl;

class IntArray
{
    int* arr;
    int size;

public:
    IntArray();
    IntArray(int _size);
    IntArray(int _size, int _value);
    IntArray(int _arr[], int _size);
    IntArray(IntArray& other);
    ~IntArray();

    friend std::ostream& operator<< (std::ostream& outDevice, const IntArray& arr);
    friend std::istream& operator>> (std::istream& inDevice, IntArray& arr);

    int &operator[](int index) const;

    IntArray& operator=(IntArray& other);

    operator int() const;

    void display();
};