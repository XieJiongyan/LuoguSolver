#include <iostream>
#include <queue>

using namespace::std;

char mat[1000][1000] = { 0 };
int ans[1000][1000] = { 0 }; //0 means checking;
int n = 0;

int dirc[4] = { 1, 0, -1, 0 };
int dirr[4] = { 0, -1, 0, 1 };

queue<int> que;
int dfn = 0;

void dfs(int r, int c)
{
	if (ans[r][c] >= 0)
		return;
	ans[r][c] = 0;
	que.push(r * 1000 + c);
	dfn++;
	for (auto i1 = 0; i1 < 4; i1++)
	{
		int rn = r + dirr[i1], cn = c + dirc[i1];
		if (rn >= 0 && rn < n && cn >= 0 && cn < n && mat[r][c] != mat[rn][cn])
			dfs(rn, cn);
	}
}

int main()
{
	int m = 0;
	cin >> n >> m;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> mat[i1][i2];
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
			ans[i1][i2] = -1;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
		{
			dfn = 0;
			dfs(i1, i2);
			while (!que.empty())
			{
				ans[que.front() / 1000][que.front() % 1000] = dfn;
				que.pop();
			}
		}
	int x = 0, y = 0;
	for (auto i1 = 0; i1 < m; i1++)
	{
		cin >> x >> y;
		cout << ans[x - 1][y - 1] << endl;
	}
	return 0;
}