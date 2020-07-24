#include <iostream>
#include <cmath>

using namespace::std;

void f(long);

int main()
{
	long n = 0;
	cin >> n;
	f(n);
	system("pause");
	return 0;
}

void f(long n)
{
	if (n == 1)
		cout << "2(0)";
	else if (n == 2)
		cout << "2";
	else
	{
		long m = n;
		int id = 0;
		while (m != 1)
		{
			if (m % 2 == 1)
			{
				f(n - pow(2, id));
				cout << "+";
				f(pow(2, id));
				break;
			}
			else
			{
				id++;
				m /= 2;
			}
		}
		if (m == 1)
		{
			cout << "2(";
			f(id);
			cout << ")";
		}
	}
}