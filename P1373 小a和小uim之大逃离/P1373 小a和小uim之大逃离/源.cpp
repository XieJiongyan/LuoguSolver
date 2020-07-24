#include <iostream>

#define NUMMAX 1000000007
using namespace::std;

int dirr[2] = { 1, 0 };
int dirc[2] = { 0, 1 };
int vdir[2] = { 1, -1 };
int dp[800][800][2][16] = { 0 };// r, c, even or odd, k
int mat[800][800] = { 0 };
int main()
{
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			cin >> mat[i1][i2];
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
		{
			dp[i1][i2][1][mat[i1][i2]]++;
			for (auto i3 = 0; i3 < 2; i3++)
				for (auto i4 = 0; i4 < 2; i4++)
				{
					int rb = i1 - dirr[i4], cb = i2 - dirc[i4];
					if (rb >= 0 && cb >= 0)
						for (auto i5 = 0; i5 < k + 1; i5++)
							dp[i1][i2][i3][i5] = (dp[rb][cb][2 - i3 - 1][(i5 + vdir[i3] * mat[i1][i2] + k + 1) % (k + 1)] + dp[i1][i2][i3][i5]) % NUMMAX;
				}
		}
	long long ans = 0;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			ans = (dp[i1][i2][0][0] + ans) % NUMMAX;
	cout << ans << endl;
	return 0;
}