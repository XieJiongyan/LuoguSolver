#include <iostream>

using namespace::std;

int main()
{
	int m = 0, n = 0;
	int k = 0, ge = 0;
	int a[20][20] = { 0 };
	cin >> m >> n >> k;
	for (auto i = 0; i < m; i++)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> a[i][i2];
	int x = -1, y = -1;
	while (true)
	{
		long l = 0;
		int xf = 0, xf2 = 0;
		for (auto i = 0; i < m; ++i)
			for (auto i2 = 0; i2 < n; i2++)
			{
				if (a[i][i2] > l)
				{
					l = a[i][i2];
					xf = i;
					xf2 = i2;
				}
			}
		if (l == 0)
			break;
		int kl = 0;
		if (x == -1)
			kl = xf + 3 + xf;
		else
			kl = abs(xf - x) + abs(xf2 - y) + xf + 2;
		if (k >= kl)
		{
			if (x == -1)
				k -= xf + 2;
			else
				k -= abs(xf - x) + abs(xf2 - y) + 1;
			ge += l;
			x = xf;
			y = xf2;
			a[xf][xf2] = 0;
		}
		else
			break;
	}
	cout << ge;
	system("pause");
	return 0;
}