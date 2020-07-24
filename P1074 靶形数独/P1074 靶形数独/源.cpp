#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

short sdk[9][9] = { 0 };
long long ro[9] = { 0 };
long long co[9] = { 0 };
long long fi[9] = { 0 };

long ans = 10000;
vector<int> cng[99];

void qfl(int r, int c)
{

void dfs(int st, int r, int c)
{
	//if (sdk[0][1] == 5 && sdk[0][2] == 4 && sdk[2][0] == 6)
	//{
	//	for (auto i1 = 0; i1 < 9; i1++)
	//	{
	//		for (auto i2 = 0; i2 < 9; i2++)
	//			cout << sdk[i1][i2] << ' ';
	//		cout << endl;
	//	}
	//	cout << endl;
	//	system("pause");
	//}
	int x = (ro[r] | co[c] | fi[(r / 3) * 3 + c / 3]) ^ 0x3fe;
	if (st == 80 && x)
	{
		long ansa = 45 * 9 * 6;
		int x = 0;
		while (++x < 5)
		{
			for (auto i1 = x; i1 < 9 - x; i1++)
				for (auto i2 = x; i2 < 9 - x; i2++)
					ansa += sdk[i1][i2];
		}
		ans = min(ans, ansa);
		return;
	}
	while (x)
	{
		long long ll = x & -x;
		int ind = 1;
		for (; (1 << ind) < ll; ind++)
			;
		sdk[r][c] = ind;
		ro[r] += ll;
		co[c] += ll;
		fi[(r / 3) * 3 + c / 3] += ll;
		bool b1 = true;
		for (auto i1 = 0; i1 < 9 && b1; i1++)
			for (auto i2 = 0; i2 < 9 && b1; i2++)
				if (!sdk[i1][i2] && i1 * 9 + i2 > r * 9 + c)
				{
					dfs(st + 1, i1, i2);
					b1 = false;
				}
		sdk[r][c] = 0;
		ro[r] -= ll;
		co[c] -= ll;
		fi[(r / 3) * 3 + c / 3] -= ll;
		x -= ll;
	}
}
int main()
{
	int fid = 0;
	for (auto i1 = 0; i1 < 9; i1++)
		for (auto i2 = 0; i2 < 9; i2++)
			cin >> sdk[i1][i2];
	for (auto i1 = 0; i1 < 9; i1++)
		for (auto i2 = 0; i2 < 9; i2++)
			if (sdk[i1][i2])
			{
				short nuh = sdk[i1][i2];
				ro[i1] += 1 << nuh;
				co[i2] += 1 << nuh;
				fi[(i1 / 3) * 3 + i2 / 3] += 1 << nuh;
				fid++;
			}
	for (auto i1 = 0; i1 < 9; i1++)
		for (auto i2 = 0; i2 < 9; i2++)
			if (!sdk[i1][i2])
			{
				dfs(fid, i1, i2);
				break;
			}
	if (ans != 10000)
		cout << ans;
	else
		cout << "-1" << endl;
	system("pause");
	return 0;
}