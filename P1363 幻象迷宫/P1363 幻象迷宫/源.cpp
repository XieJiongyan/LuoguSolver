#include <iostream>
#include <vector>
#include <string>

using namespace::std;

short dirr[4] = { 0, -1, 0, 1 };
short dirc[4] = { 1, 0, -1, 0 };

long mat[1500][1500] = { 0 };
char matc[1500][1500] = { 'J' };

bool b1 = true;
long n = 0, m = 0;

void dfs(int r, int c)
{
	int rf = (r + n * 1500) % n, cf = (c + m * 1500) % m;
	if (mat[rf][cf] == -100000001 || !b1 || matc[rf][cf] == '#')
		return;
	if (mat[rf][cf] == r / n * 1500 + c / m)
		return;
	if (mat[rf][cf] != 0 && mat[rf][cf] != r / n * 1500 + c / m && mat[rf][cf] != -100000002)
	{
		b1 = false;
		return;
	}
	mat[rf][cf] = r / n * 1500 + c / m;//once;
	for (auto i1 = 0; i1 < 4; i1++)
		dfs(r + dirr[i1], c + dirc[i1]);
	mat[rf][cf] = -100000001;
}

int main()
{
	vector<string> v;
	while (cin >> n >> m)
	{
		b1 = true;
		long r1 = 0, c1 = 0;
		for (auto i1 = 0; i1 < n; i1++)
			for (auto i2 = 0; i2 < m; i2++)
			{
				cin >> matc[i1][i2];
				if (matc[i1][i2] == 'S')
				{
					r1 = i1;
					c1 = i2;
				}
			}
		for (auto i1 = 0; i1 < n; i1++)
			for (auto i2 = 0; i2 < m; i2++)
				mat[i1][i2] = -100000002;
		dfs(r1 + n * 1500, c1 + m * 1500);
		if (b1 == false)
			v.push_back("Yes");
		else
			v.push_back("No");
	}
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
		cout << *i1 << endl;
	system("pause");
	return 0;
}