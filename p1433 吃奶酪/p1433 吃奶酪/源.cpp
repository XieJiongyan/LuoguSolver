#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace::std;

int n = 0;
vector<double> vx;
vector<double> vy;
double dis[15][15];
double ans = 10000000000.0;
void dfs(int hi, long long x, double len)
{
	if (len >= ans)
		return;
	if (x + 1 == (1 << n + 1))
		ans = len;
	else
		for (auto i1 = 1; i1 <= n; i1++)
			if ((x & (1 << i1)) == 0)
				dfs(i1, x + (1 << i1), len + dis[i1][hi]);
	return;
}

int main()
{
	cin >> n;
	vx.push_back(0.0);
	vy.push_back(0.0);
	vx.resize(n + 1);
	vy.resize(n + 1);
	for (auto i1 = 1; i1 <= n; i1++)
		cin >> vx[i1] >> vy[i1];
	for (auto i1 = 0; i1 <= n; i1++)
		for (auto i2 = 0; i2 <= n; i2++)
			dis[i1][i2] = sqrt((vx[i1] - vx[i2]) * (vx[i1] - vx[i2]) + (vy[i1] - vy[i2]) * (vy[i1] - vy[i2]));
	dfs(0, 1, 0);
	printf("%.2f", ans);
	system("pause");
	return 0;
}