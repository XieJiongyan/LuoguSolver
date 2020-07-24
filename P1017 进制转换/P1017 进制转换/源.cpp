#include <iostream>
#include <vector>
#include <cmath>

using namespace::std;

int main()
{
	vector<long> v(100, 0);
	long l = 0, r = 0;
	cin >> l >> r;
	long la = l;
	while (l != 0)
		for (auto i = -1; ; ++i)
			if (pow(r, i + 2) * l > 0 && abs(pow(r, i + 2)) >= abs(l))
			{
				long lp = 0;
				for (auto i2 = i; i2 >= 0; i2 -= 2)
					lp += (-1 - r) * pow(r, i2);
				if (abs(lp) >= abs(l))
				{
					v[i] += l / pow(r, i);
					l %= static_cast<long>(pow(r, i));
				}
				else if (l == 1)
				{
					v[0] += 1;
					l = 0;
				}
				else
				{
					v[i + 2] += 1;
					l -= pow(r, i + 2);
				}
				break;
			}
	cout << la << '=';
	bool b1 = true;
	for (auto i = v.rbegin(); i < v.rend(); ++i)
		if (b1 && *i == 0)
			continue;
		else
		{
			b1 = false;
			if (*i <= 9)
				cout << *i;
			else
				cout << static_cast<char>(*i - 10 + 'A');
		}
	cout << "(base" << r << ')' << endl;
	system("pause");
	return 0;
}
