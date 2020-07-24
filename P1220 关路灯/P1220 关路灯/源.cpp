#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int dp[50][51][2] = { 0 };

int main()
{
	int n = 0, c = 0;
	cin >> n >> c;
	c--;
	vector<int> v(n);
	vector<int> vdi(n);
	for (auto i1 = 0; i1 < 50; i1++)
		for (auto i2 = 0; i2 < 51; i2++)
			for (auto i3 = 0; i3 < 2; i3++)
				dp[i1][i2][i3] = 0x7777ffff;
	//int alp = 0;
	for (auto i1 = 0; i1 < n; i1++)
		cin >> vdi[i1] >> v[i1];
	dp[c][c + 1][1] = dp[c][c + 1][0] = 0;
	for (auto i1 = 2; i1 < n + 1; i1++)
		for (auto i2 = max(0, c - i1 + 1); i2 + i1 < n + 1; i2++)
		{
			int res = 0;
			const int& rp = i2 + i1;
			for (auto i3 = 0; i3 < n; i3++)
				if (i3 < i2 || i3 >= rp)
					res += v[i3];
			if (i2 != c)
				dp[i2][rp][0] = min(dp[i2 + 1][rp][0] + (res + v[i2]) * (vdi[i2 + 1] - vdi[i2]), dp[i2 + 1][rp][1] + (res + v[i2]) * (vdi[rp - 1] - vdi[i2]));
			if (rp - 1 != c)
				dp[i2][rp][1] = min(dp[i2][rp - 1][0] + (res + v[rp - 1]) * (vdi[rp - 1] - vdi[i2]), dp[i2][rp - 1][1] + (res + v[rp - 1]) * (vdi[rp - 1] - vdi[rp - 2]));
		}
	cout << min(dp[0][n][0], dp[0][n][1]) << endl;
	return 0;
}