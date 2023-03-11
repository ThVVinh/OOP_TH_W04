#include<iostream>
#include<string.h>
#include<limits.h>
#include<sstream>
using std::cin, std::cout, std::endl, std::string;

template<class T>
class MyVector{

private:
    T *arr;
    int size;

public:
    // empty array
    MyVector():arr(NULL), size(0){}
    
    // n zeros
    MyVector(int n)
    {
        size = n;
        arr = new T[size]{T()};
    }

    MyVector(T *a, int n): MyVector(n)
    {
        for(int i = 0; i < n; i++)
            arr[i] = a[i];
    }

    MyVector(const MyVector &v): MyVector()
    {
        *this = v;
    }

    ~MyVector()
    {
        if(arr != NULL)
        {
            delete[]arr;

            arr = NULL;

            size = 0;
        }
    }

    MyVector& operator=(const MyVector& other)
    {
        clear();
        
        size = other.size;
        arr = new T[size];

        for(int i = 0; i < size; i++)
            arr[i] = other.arr[i];
        
        return *this;
    }

    T& operator[](int index) const
    {
        if(index >= size || index < 0)
            throw std::runtime_error("invalid index");
        return arr[index];
    }

    int getSize() const
    {
        return size;
    }

    T getItem(int index)
    {
        return arr[index];
    }

    void setItem(T value, int index)
    {
        arr[index] = value;
    }

    void add(T value)
    {
        T* temp = arr;
        
        ++size;

        arr = new T[size];

        int i;
        for(i = 0; i < size - 1; i++)
            arr[i] = temp[i];
        arr[i] = value;

        delete[] temp;
        temp = NULL;
    }

    void addRange(T *a, int n)
    {
        T* temp = arr;

        arr = new T[size + n];

        for(int i = 0; i < size; i++)
            arr[i] = temp[i];

        for(int i = 0; i < n; i++)
            arr[size + i] = temp[i];

        size += n;
    }

    void clear()
    {
        if(arr != NULL)
        {
            delete[]arr;

            arr = NULL;

            size = 0;
        }
    }

    bool contains(T value)
    {
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == value)
                return true;
        }

        return false;
    }

    void toArray(T *&_arr, int &n)
    {
        if(_arr != NULL)
            delete[]_arr;

        n = size;

        _arr = new T[n]{};

        for(int i = 0; i < size; i++)
            _arr[i] = arr[i];
    }

    bool equals(const MyVector &v)
    {
        if(size != v.getSize())
            return false;
        
        for(int i = 0; i < size; i++)
        {
            if(arr[i] != v.arr[i])
                return false;
        }

        return true;
    }

    int indexOf(T value)
    {
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == value)
                return i;
        }

        return -1;
    }

    int lastIndexOf(T value)
    {
        for(int i = size - 1; i >= 0; i--)
        {
            if(value == arr[i])
                return i;
        }

        return -1;
    }

    void insert(T value, int index)
    {
        if(accessValid(index))
        {
            add(value);

            for(int i = size - 1; i > index; i--)
            {
                swap(i, i - 1);
            }
        }
    }

    void swap(int index1, int index2)
    {
        T temp = arr[index1];

        arr[index1] = arr[index2]; 

        arr[index2] = temp;
    }

    friend std::ostream& operator<<(std::ostream& outDev, const MyVector<T>& v)
    {
        cout << "[ ";

        if(v.arr != NULL)
        {
            for(int i = 0; i < v.size; i++)
                outDev << "arr[" << i << "] = " << v[i] << " ";
        }
        
        cout << "]";
        cout << endl;

        return outDev;
    }

    bool accessValid(int index)
    {
        if(index >= size || index <= 0)
        {
            cout << "Invalid" << endl;
            return 0;
        }

        return true;
    }

    void remove(T value)
    {
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == value)
            {
                moveFromIndexToEnd(i);

                removeLast();

                --i; //phan tu cuoi bi doi vao index = value
            }
        }
    }

    void removeAt(int index)
    {
        if(!accessValid(index))
        {
            return;
        }

        moveFromIndexToEnd(index);

        removeLast();
    }

    void removeLast()
    {
        int new_size = size - 1;

        T* new_arr = new T[new_size];

        for(int i = 0; i < new_size; i++)
            new_arr[i] = arr[i];

        delete[]arr;

        arr = new_arr;
        size= new_size;
    }

    void moveFromIndexToEnd(int index)
    {
        if(!accessValid(index))
        {
            return;
        }

        for(int i = index; i < size - 1; i++)
        {
            swap(i, i + 1);
        }
    }

    void reverse()
    {
        for(int i = 0; i < size / 2; i++)
        {
            swap(i, size - 1 - i);
        }
    }

    string toString()
    {
        std::stringstream ss;

        for(int i = 0; i < size; i++)
            ss << arr[i];

        return ss.str();
    }

    void bubbleSort()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size - i - 1; j++)
            {
                if(arr[j] > arr[j+1])
                    swap(j, j+1);
            }
        }
    }

    void sortAsc()
    {
        bubbleSort();
    }

    void sortDesc()
    {
        bubbleSort();
        reverse();
    }

};

template<class T>
void swap(T& a, T& b)
{
    T temp = a;

    a = b; 

    b = temp;
}

class Fraction
{
private:
        int numerator;
        int denominator;

public:
    Fraction(): numerator(0), denominator(1)
    {

    }

    Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator)
    {

    }

    Fraction(const Fraction& other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    ~Fraction()
    {
        //cout << "Call Destructor of " << *this << endl; 
    }


    friend std::ostream& operator<< (std::ostream& outDevice, const Fraction& frac)
    {
        if(frac.denominator < 0)
            outDevice << (-1 * frac.numerator) << "/" << (-1* frac.denominator);
        else outDevice << frac.numerator << "/" << frac.denominator;

        return outDevice;
    }
    friend std::istream& operator>> (std::istream& inDevice,  Fraction& frac)
    {
        cout << "Enter fraction (a/b): ";

        char c = '/';

        inDevice >> frac.numerator >> c >> frac.denominator;

        return inDevice;
    }

    Fraction& operator=(const Fraction& other)
    {
        numerator = other.numerator;
        denominator = other.denominator;

        return *this;
    }

    float operator-(const Fraction& other)
    {
        return 1.0 * ((numerator * other.denominator) - (denominator * other.numerator)) / (other.denominator * denominator);
    }

    bool operator==(const Fraction& other)
    {
        return *this - other == 0;
    }

    bool operator>(const Fraction& other)
    {
        return *this - other > 0;    
    }

    bool operator!=(const Fraction& other)
    {
        return *this - other != 0;
    }
};