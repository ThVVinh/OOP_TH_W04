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

    int* test = NULL;
    int n_test = 0;

    m3.toArray(test, n_test);

    for(int i = 0; i < n_test; i++)
        cout << test[i] << " ";
    cout << endl;
}