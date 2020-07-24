#include <iostream>
#include <algorithm>

using namespace::std;

int up[2000][2000] = { 0 };
int ale[2000][2000] = { 0 };
int ari[2000][2000] = { 0 };
int mat[2000][2000] = { 0 };

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			cin >> mat[i1][i2];
	for (auto i1 = 0; i1 < m; i1++)
		up[0][i1] = 1;
	for (auto i1 = 0; i1 < n; i1++)
	{
		ale[i1][0] = 1;
		ari[i1][m - 1] = 0;
	}
	for (auto i1 = 1; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			if (mat[i1][i2] != mat[i1 - 1][i2])
				up[i1][i2] = up[i1 - 1][i2] + 1;
			else
				up[i1][i2] = 1;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 1; i2 < m; i2++)
			if (mat[i1][i2] != mat[i1][i2 - 1])
				ale[i1][i2] = ale[i1][i2 - 1] + 1;
			else
				ale[i1][i2] = 1;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = m - 2; i2 > -1; i2--)
			if (mat[i1][i2] != mat[i1][i2 + 1])
				ari[i1][i2] = ari[i1][i2 + 1] + 1;
			else
				ari[i1][i2] = 0;
	int mas = 0, mar = 0;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
		{
			int y = up[i1][i2];
			int x = 0x7777ffff;
			for (auto i3 = i1; i3 > i1 - y; i3--)
				x = min(x, ale[i3][i2] + ari[i3][i2]);
			mas = max(mas, min(x, y) * min(x, y));
			mar = max(mar, x * y);
		}
	cout << mas << endl << mar << endl;
	return 0;
}