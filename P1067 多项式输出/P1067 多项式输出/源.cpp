#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	int n = 0;
	cin >> n;
	vector<long> v(n + 1);
	for (auto i = v.begin(); i < v.end(); ++i)
		cin >> *i;
	for (auto i = v.begin(); i < v.end(); ++i)
	{
		if (*i < 0)
			cout << "-";
		else if (*i > 0 && i > v.begin())
			cout << "+";
		if (*i != 0)
		{
			if (*i < -1)
				cout << -*i;
			else if (*i > 1)
				cout << *i;
			if (n - (i - v.begin()) >= 2)
				cout << "x^" << n - (i - v.begin());
			else if (n - (i - v.begin()) == 1)
				cout << "x";
			else if (i == v.end() - 1 &&(*i == 1 || *i ==-1))
				cout << "1";
		}
	}
	system("pause");
	return 0;
}