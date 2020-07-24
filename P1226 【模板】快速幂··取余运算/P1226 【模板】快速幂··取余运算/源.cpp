#include <iostream>
#include <cmath>

using namespace::std;

int main()
{
	long b = 0, p = 0, k = 0;
	cin >> b >> p >> k;
	long x = 1;
	long bx = b % k;
	int ti = 0;
	for (auto i = 0; i < p; ++i)
	{
		x *= bx;
		x %= k;
		if (x == 1)
		{
			ti = i + 1;
			break;
		}
	}
	if(ti != 0)
		for (auto i = 0; i < p% ti; ++i)
		{
			x *= bx;
			x %= k;
		}
	if (p == 0)
		x = 1 % k;
	cout << b << '^' << p << " mod " << k << "=" << x << endl;
	system("pause");
	return 0;
}