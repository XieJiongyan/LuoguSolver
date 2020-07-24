#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace::std;

int dp[200] = { -1 };

int dir[2] = { -1, 1 };
int main()
{
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	if (a == b)
	{
		cout << 0 << endl;
		return 0;
	}
	a--, b--;
	vector<int> v(n);
	for (auto& i1 : v)
		cin >> i1;
	for (auto i1 = 0; i1 < n; i1++)
		dp[i1] = -1;
	queue<int> que;
	que.push(a);
	dp[a] = 0;
	int quv = 0;
	int nc = n;
	bool b1 = true;
	while (b1)
	{
		b1 = false;
		queue<int> quec;
		while (!que.empty())
		{
			quv = que.front();
			que.pop();
			for (auto i1 = 0; i1 < 2; i1++)
			{
				int stn = quv + dir[i1] * v[quv];
				if (stn < 0 || stn >= n)
					continue;
				if (stn == b)
				{
					cout << dp[quv] + 1 << endl;
					exit(0);
				}
				if (dp[stn] == -1)
				{
					dp[stn] = dp[quv] + 1;
					quec.push(stn);
				}
			}
		}
		while (!quec.empty())
		{
			que.push(quec.front());
			quec.pop();
			b1 = true;
		}
	}
	cout << -1 << endl;
	return 0;
}