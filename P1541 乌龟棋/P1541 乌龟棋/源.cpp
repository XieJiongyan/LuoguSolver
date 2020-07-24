#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

long dp[40][40][40][40] = { 0 };
long c[4] = { 1, 1, 1, 1 };

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<long> vgr(n, 0);
	for (auto i1 = vgr.begin(); i1 < vgr.end(); i1++)
		cin >> *i1;
	int ic = 0;
	for (auto i1 = 0; i1 < m; i1++)
	{
		cin >> ic;
		c[ic - 1]++;
	}
	for (auto i1 = 0; i1 < c[0]; i1++)
		for (auto i2 = 0; i2 < c[1]; i2++)
			for (auto i3 = 0; i3 < c[2]; i3++)
				for (auto i4 = 0; i4 < c[3]; i4++)
				{
					long& thv = dp[i1][i2][i3][i4];
					if (i1 >= 1)
						thv = max(thv, dp[i1 - 1][i2][i3][i4]);
					if (i2 >= 1)
						thv = max(thv, dp[i1][i2 - 1][i3][i4]);
					if (i3 >= 1)
						thv = max(thv, dp[i1][i2][i3 - 1][i4]);
					if (i4 >= 1)
						thv = max(thv, dp[i1][i2][i3][i4 - 1]);
					thv += vgr[i1 + i2 * 2 + i3 * 3 + i4 * 4];
				}
	cout << dp[c[0] - 1][c[1] - 1][c[2] - 1][c[3] - 1] << endl;
	system("pause");
	return 0;
}