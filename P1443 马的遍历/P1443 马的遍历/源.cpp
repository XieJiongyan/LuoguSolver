#include <iostream>
#include <queue>
#include <cstdio>

using namespace::std;

int n = 0, m = 0;
int mat[400][400] = { 0 };
int dirr[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dirc[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
queue<int> que;

void bfs(int num)
{
	if (que.empty())
		return;
	int r = 0, c = 0;
	int siz = que.size();
	for (auto i1 = 0; i1 < siz; i1++)
	{
		r = que.front() / 1000;
		c = que.front() % 1000;
		que.pop();
		if (mat[r][c] != -1)
			continue;
		mat[r][c] = num;
		int rn = 0, cn = 0;
		for (auto i1 = 0; i1 < 8; i1++)
		{
			rn = r + dirr[i1], cn = c + dirc[i1];
			if (rn >= 0 && rn < n && cn >= 0 && cn < m)
				que.push(rn * 1000 + cn);
		}
	}
	bfs(num + 1);
}

int main()
{
	cin >> n >> m;
	int r = 0, c = 0;
	cin >> r >> c;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			mat[i1][i2] = -1;
	que.push((r - 1) * 1000 + c - 1);
	bfs(0);
	for (auto i1 = 0; i1 < n; i1++)
	{
		for (auto i2 = 0; i2 < m; i2++)
			printf("%-5d", mat[i1][i2]);
		cout << endl;
	}
	return 0;
}