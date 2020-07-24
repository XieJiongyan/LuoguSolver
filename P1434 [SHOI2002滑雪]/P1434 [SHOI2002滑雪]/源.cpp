#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int ter[100][100];
int tert[100][100] = { 0 };

int dirx[4] = { 1, 0, -1, 0 };
int diry[4] = { 0, -1, 0, 1 };
int col = 0, row = 0;

long dfs(int x, int y)
{
	if (tert[x][y])
		return tert[x][y];
	long rev = 1;
	for (auto i1 = 0; i1 < 4; i1++)
	{
		int xn = x + dirx[i1];
		int yn = y + diry[i1];
		if (xn >= 0 && xn < col && yn >= 0 && yn < row &&ter[y][x] > ter[y + diry[i1]][x + dirx[i1]])
			rev = max(rev, dfs(xn, yn) + 1);
	}
	tert[x][y] = rev;
	return rev;
}

int main()
{
	cin >> row >> col;
	for (auto i1 = 0; i1 < row; i1++)
		for (auto i2 = 0; i2 < col; i2++)
			cin >> ter[i1][i2];
	vector<int> v;
	for (auto i1 = 0; i1 < row; i1++)
		for (auto i2 = 0; i2 < col; i2++)
		{
			bool b1 = true;
			for (auto i3 = 0; i3 < 4; i3++)
			{
				int xt = i2 + dirx[i3];
				int yt = i1 + diry[i3];
				if (xt >= 0 && xt < col && yt >= 0 && yt < row && ter[i1][i2] < ter[yt][xt])
				{
					b1 = false;
					break;
				}
			}
			if (b1)
				v.push_back(i1 * 100 + i2);
		}
	long ans = 0;
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
		ans = max(ans, dfs(*i1 % 100, *i1 / 100));
	cout << ans << endl;
	system("pause");
	return 0;
}