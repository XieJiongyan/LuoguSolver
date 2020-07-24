#include <iostream>
#include <algorithm>

using namespace::std;

int main()
{
	long m = 0, n = 0;
	long co[31][30] = { 0 };
	cin >> n >> m;
	co[0][0] = 1;
	for (auto i = 1; i <= m; ++i)
		for (auto i2 = 0; i2 < n; ++i2)
			if (i2 == 0)
				co[i][i2] += co[i - 1][i2 + 1] + co[i - 1][n - 1];
			else if (i2 == n - 1)
				co[i][i2] += co[i - 1][i2 - 1] + co[i - 1][0];
			else
				co[i][i2] += co[i - 1][i2 - 1] + co[i - 1][i2 + 1];
	cout << co[m][0];
	system("pause");
	return 0;
}

