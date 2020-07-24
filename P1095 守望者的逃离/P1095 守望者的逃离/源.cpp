#include <iostream>
#include <algorithm>

using namespace::std;

int dp[300000] = { 0 };

int main()
{
	long m = 0, s = 0, t = 0;
	cin >> m >> s >> t;
	t += 1;
	int ir = 0;
	for (auto i1 = 1; i1 < t; i1++)
	{
		if (m >= 10)
		{
			dp[i1] = dp[i1 - 1] + 60;
			m -= 10;
		}
		else
		{
			if (ir == 0)
				ir = i1;
			dp[i1] = dp[i1 - 1];
			m += 4;
		}
	}
	for (auto i1 = ir; i1 < t; i1++)
		dp[i1] = max(dp[i1], dp[i1 - 1] + 17);
	bool b1 = true;
	for (auto i1 = 0; i1 < t; i1++)
	{
		if (dp[i1] >= s)
		{
			cout << "Yes" << endl << i1;
			b1 = false;
			break;
		}
	}
	if (b1)
		cout << "No" << endl << dp[t - 1];
	system("pause");
	return 0;
}