#include <iostream>
#include <algorithm>

using namespace::std;

int dp[100][100][4] = { 0 };

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	for (auto i1 = 0; i1 < m; i1++)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> dp[i1][i2][0];
	for (auto i1 = 0; i1 < m; i1++)
		if (dp[i1][0][0])
			for (auto i2 = 1; i2 < 4; i2++)
				dp[i1][0][i2] = 1;
	for (auto i1 = 0; i1 < n; i1++)
		if (dp[0][i1][1])
			for (auto i2 = 1; i2 < 4; i2++)
				dp[0][i1][i2] = 1;
	int ans = 1;
	for (auto i1 = 1; i1 < m; i1++)
		for (auto i2 = 1; i2 < n; i2++)
		{
			if (dp[i1][i2][0])
			{
				dp[i1][i2][1] = dp[i1 - 1][i2][1] + 1;
				dp[i1][i2][2] = dp[i1][i2 - 1][2] + 1;
				dp[i1][i2][3] = min(min(dp[i1 - 1][i2][1], dp[i1][i2 - 1][2]), dp[i1 - 1][i2 - 1][3]) + 1;
				ans = max(ans, dp[i1][i2][3]);
			}
		}
	cout << ans << endl;
	system("pause");
	return 0;
}