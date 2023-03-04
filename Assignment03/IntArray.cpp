#include"IntArray.h"

IntArray::IntArray():arr(NULL), size(0)
{

}

IntArray::IntArray(int _size)
{
    if(_size > 0)
    {
        size = _size;

        arr = new int[size];

        for(int i = 0; i < size; i++)
            arr[i] = 0;
    }
}

IntArray::IntArray(int _size, int _value)
{
    if(_size > 0)
    {
        size = _size;

        arr = new int[size];

        for(int i = 0; i < size; i++)
            arr[i] = _value;
    }
}

IntArray::IntArray(int _arr[], int _size): IntArray(_size)
{

    for(int i = 0; i < size; i++)
        arr[i] = _arr[i];
}

IntArray::IntArray(IntArray& other): IntArray()
{
    *this = other;
}

IntArray::~IntArray()
{
    if(size != 0)
    {
        delete[]arr;
        
        arr = NULL;

        size = 0;
    }
}

std::ostream& operator<< (std::ostream& outDevice, const IntArray& arr)
{
    if(arr.arr != NULL)
    {
        for(int i = 0; i < arr.size; i++)
            outDevice << "arr[" << i << "] = " << arr[i] << " ";
    }

    cout << endl;

    return outDevice;
}
std::istream& operator>> (std::istream& inDevice, IntArray& arr)
{
    for(int i = 0; i < arr.size; i++)
    {
        cout << "arr[" << i << "] = ";
        inDevice >> arr[i];
    }

    return inDevice;
}

void IntArray::display()
{
    if(arr != NULL)
    {
        for(int i = 0; i < size; i++)
            cout << "arr[" << i << "] = " << arr[i] << ", ";
    }

    cout << endl;
}

int &IntArray::operator[](int index) const
{
    if (index >= size || index < 0) {
        throw std::runtime_error("invalid index");
    }

    return arr[index];
}

IntArray& IntArray::operator=(IntArray& other)
{
    if(arr != NULL)
        delete[]arr;

    size = other.size;

    arr = new int[size];

    for(int i = 0; i < size; i++)
        arr[i] = other[i];

    return *this;
}

IntArray::operator int() const
{
    return size;
}