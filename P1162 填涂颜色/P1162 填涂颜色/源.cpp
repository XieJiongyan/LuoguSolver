#include <iostream>
#include <vector>

using namespace::std;

int mat[100][100] = { 0 };
int mata[100][100] = { 0 };
int dirx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int diry[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
vector<int> sa;
int n = 0;

int dfs(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n || mata[x][y] == 2)
		return -2;
	if (mata[x][y])
		return 0;
	if (mat[x][y] == 1)
		return 1;
	mata[x][y] = 1;
	for (auto i1 = 0; i1 < 4; i1++)
		if (dfs(x + dirx[i1], y + diry[i1]) == -2)
		{
			mata[x][y] = 2;
			return -2;
		}
	sa.push_back(x * n + y);
	return 2;
}

int main()
{
	cin >> n;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> mat[i1][i2];
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
		{
			sa.clear();
			if (dfs(i1, i2) == 2)
				for (auto i3 = sa.begin(); i3 < sa.end(); i3++)
					mat[*i3 / n][*i3%n] = 2;
		}
	for (auto i1 = 0; i1 < n; i1++)
	{
		for (auto i2 = 0; i2 < n; i2++)
			cout << mat[i1][i2] << ' ';
		cout << endl;
	}
	system("pause");
	return 0;
}