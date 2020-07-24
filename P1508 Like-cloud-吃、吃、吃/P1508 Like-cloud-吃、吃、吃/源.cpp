#include <iostream>
#include <algorithm>

using namespace::std;

long mat[200][200];

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	for (auto i1 = 0; i1 < m; i1++)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> mat[i1][i2];
	for (auto i1 = 1; i1 < m; i1++)
		for (auto i2 = max(0, n / 2 + i1 - m); i2 < min(n, n / 2 + m - i1 + 1); i2++)
		{
			long rev = mat[i1 - 1][i2] + mat[i1][i2];
			if (i2 > 0)
				rev = max(rev, mat[i1 - 1][i2 - 1] + mat[i1][i2]);
			if (i2 < n - 1)
				rev = max(rev, mat[i1 - 1][i2 + 1] + mat[i1][i2]);
			mat[i1][i2] = rev;
		}
	cout << max(max(mat[m - 1][n / 2], mat[m - 1][n / 2 - 1]), mat[m - 1][n / 2 + 1]) << endl;
	system("pause");
	return 0;
}