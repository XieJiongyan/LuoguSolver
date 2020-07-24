#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

long dp[200][200] = { 0 };

int main()
{
	int n = 0;
	cin >> n;
	vector<long> vnf(n, 0);
	for (auto i1 = vnf.begin(); i1 < vnf.end(); i1++)
		cin >> *i1;
	for (auto i1 = 0; i1 < n; i1++)
		vnf.push_back(vnf[i1]);
	for (auto i1 = 2; i1 < n + 1; i1++)
		for (auto i2 = 0; i2 < n * 2 - i1; i2++)
		{
			long& thv = dp[i2][i2 + i1];
			//int ii3 = 0;
			for (auto i3 = i2 + 1; i3 < i2 + i1; i3++)
				if (thv < dp[i2][i3] + dp[i3][i2 + i1] + vnf[i2] * vnf[i3] * vnf[i2 + i1])
				//{
					thv = max(thv, dp[i2][i3] + dp[i3][i2 + i1] + vnf[i2] * vnf[i3] * vnf[i2 + i1]);
					//ii3 = i3;
				//}
			//cout << i2 << " - " << i2 + i1 << " = " << dp[i2][ii3] << " + " << dp[ii3][i2 + i1] << " + ¡¤¡¤¡¤ = " << thv << "   " << ii3 << endl;
		}
	long ans = 0;
	for (auto i1 = 0; i1 < n; i1++)
		ans = max(ans, dp[i1][i1 + n]);
	cout << ans;
	system("pause");
	return 0;
}