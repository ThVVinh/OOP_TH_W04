#include"MyVector.h"

int main()
{
    MyVector<int> m1;
	MyVector<int> m2(7);
	int a[100];
	int n=7;
	for(int i=0;i<n;i++)
	{
		a[i]=i;
	}
	MyVector<int> m3(a,n);
	MyVector<int> m4(m2);
	MyVector<int> m5;
	m5=m2;

	cout<<m2;

	cout << m3.getItem(3);
	m3.setItem(4,1);
    cout << endl;
	cout << m1 << m2 << m3 << m4 << m5;
    cout << endl;

    m5.add(10);
    cout << m5;

    m5.addRange(a, 7);
    cout << m5;

    cout << m5.contains(10) << endl;

    int* b = NULL;
    int n_b = 0;

    m3.toArray(b, n_b);

    for(int i = 0; i < n_b; i++)
        cout << b[i] << " ";
    cout << endl;

	MyVector<int> m6(m3);
	int num = 6;
	cout << m6.equals(m3) << endl;
	cout << m6.indexOf(num) << endl;

	num = 4;
	m6.add(num);
	m6.add(12);
	m6.add(11);
	m6.add(25);
	m6.add(6);
	cout << m6 << endl;
	cout << m6.lastIndexOf(num) << endl;

	m6.insert(num, 2);
	cout << m6 << endl;

	m6.remove(num);
	cout << m6 << endl;

	int index = 1;
	m6.removeAt(index);
	cout << m6 << endl;

	m6.reverse();
	cout << m6 << endl;

	m6.sortAsc();
	cout << m6 << endl;

	m6.sortDesc();
	cout << m6 << endl;

	cout << "-----Fraction-----" << endl;
	MyVector<Fraction> f1;
	MyVector<Fraction> f2(7);
	Fraction c[100];
	int n_f = 7;

	for(int i=0;i<n_f;i++)
	{
		c[i] = Fraction(i, i + 1);;
	}
	MyVector<Fraction> f3(c,n_f);
	MyVector<Fraction> f4(f2);
	MyVector<Fraction> f5;
	f5=f2;

	cout<<f2;

	cout << f3.getItem(3);
	f3.setItem(Fraction(5,3),1);
    cout << endl;
	cout << f1 << f2 << f3 << f4 << f5;
    cout << endl;

    f5.add(Fraction(15, 12));
    cout << f5;

    f5.addRange(c, 7);
    cout << f5;

    cout << f5.contains(Fraction(5,3)) << endl;

    Fraction* d = NULL;
    int n_d = 0;

    f3.toArray(d, n_d);

    for(int i = 0; i < n_d; i++)
        cout << d[i] << " ";
    cout << endl;

	MyVector<Fraction> f6(f3);
	Fraction num_f(12, 11);
	cout << f6.equals(f3) << endl;
	cout << f6.indexOf(num_f) << endl;

	num_f = Fraction(25,6);
	f6.add(num_f);
	f6.add(Fraction(4,3));
	f6.add(Fraction(125,6));
	f6.add(Fraction(47,6));
	f6.add(Fraction(25,6));
	cout << f6 << endl;
	cout << f6.lastIndexOf(num_f) << endl;

	f6.insert(num_f, 2);
	cout << f6 << endl;

	f6.remove(num_f);
	cout << f6 << endl;

	int index_f = 1;
	f6.removeAt(index_f);
	cout << f6 << endl;

	f6.reverse();
	cout << f6 << endl;

	f6.sortAsc();
	cout << f6 << endl;

	f6.sortDesc();
	cout << f6 << endl;
};