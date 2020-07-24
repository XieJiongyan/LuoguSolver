#include <iostream>
#include <algorithm>

using namespace::std;

int dp[1001] = { 0 };

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	int in1 = 0, in2 = 0;
	for (auto i1 = 0; i1 < m; i1++)
	{
		cin >> in1 >> in2;
		for (auto i2 = n; i2 > in1 - 1; i2--)
			dp[i2] = max(dp[i2], dp[i2 - in1] + in2);
	}
	cout << dp[n] << endl;
	return 0;
}