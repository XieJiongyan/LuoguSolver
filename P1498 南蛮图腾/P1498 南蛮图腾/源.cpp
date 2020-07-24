#include <iostream>
#include <cmath>

void f(int, int);

using namespace::std;

int main()
{
	int x = 0;
	cin >> x;
	f(x, 0);
	system("pause");
	return 0;
}

void f(int x, int b)
{
	if(b == 0)
		for (auto i = 0; i < static_cast<long>(pow(2, x)); i++)
		{
			f(x, i + 1);
			cout << endl;
		}
	else if (x == 1)
		switch (b)
		{
		case 1:
			cout << " /\\ ";
			break;
		case 2:
			cout << "/__\\";
			break;
		}
	else if (b <= pow(2, x - 1))
	{
		for (auto i1 = 0; i1 < pow(2, x - 1); ++i1)
			cout << ' ';
		f(x - 1, b);
		for (auto i1 = 0; i1 < pow(2, x - 1); ++i1)
			cout << ' ';
	}
	else if (b > pow(2, x - 1))
	{
		f(x - 1, b - pow(2, x - 1));
		f(x - 1, b - pow(2, x - 1));
	}
}
