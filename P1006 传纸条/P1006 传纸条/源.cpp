#include <iostream>
#include <algorithm>

using namespace::std;

int mat[50][50] = { 0 };
int dp[99][50][50] = { 0 };

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	for (auto i1 = 0; i1 < m; i1++)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> mat[i1][i2];
	dp[1][0][1] = mat[1][0] + mat[0][1];
	for (auto i1 = 2; i1 < m + n - 1; i1++)
		for (auto i2 = max(0, i1 - m + 1); i2 < min(i1 + 1, n) - 1; i2++)
			for (auto i3 = i2 + 1; i3 < min(i1 + 1, n); i3++)
			{
				if (i2 != i3 - 1)
					dp[i1][i2][i3] = dp[i1 - 1][i2][i3 - 1];
				if (i2 > 0)
					dp[i1][i2][i3] = max(dp[i1][i2][i3], dp[i1 - 1][i2 - 1][i3 - 1]);
				if (i3 < min(i1 + 1, n) - 1 || i1 >= n)
					dp[i1][i2][i3] = max(dp[i1][i2][i3], dp[i1 - 1][i2][i3]);
				if (i2 > 0 && (i3 < min(i1 + 1, n) - 1 || i1 >= n))
					dp[i1][i2][i3] = max(dp[i1][i2][i3], dp[i1 - 1][i2 - 1][i3]);
				dp[i1][i2][i3] += mat[min(i1, m - 1) - i2 + max(0, i1 - m + 1)][i2] + mat[min(i1, m - 1) - i3 + max(0, i1 - m + 1)][i3];
				//cout << endl << i1 << ' ' << i2 << ' ' << i3 << " +=" << mat[min(i1, m - 1) - i2 + max(0, i1 - m + 1)][i2] << " + " << mat[min(i1, m - 1) - i3 + max(0, i1 - m + 1)][i3]\
				//	<< " = " << dp[i1][i2][i3];
			}
	cout << dp[m + n - 3][n - 2][n - 1] << endl;
	system("pause");
	return 0;
}