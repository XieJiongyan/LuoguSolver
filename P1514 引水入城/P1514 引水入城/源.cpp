#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int hei[500][500];
int n = 0, m = 0;
int ml = 0, mu = 0;
int bm[500][500] = { false };
int ans = 0;
int lml = 0;
vector<int> vpa;
vector<int> vus;

int dirc[4] = { 1, 0, -1, 0 };
int dirr[4] = { 0, -1, 0, 1 };

void dfs(int r, int c, int fla)
{
	if (bm[r][c] || !ml)
		return;
	bm[r][c] = fla;
	if (r == n - 1)
		ml--;
	for (auto i1 = 0; i1 < 4; i1++)
	{
		int rn = r + dirr[i1], cn = c + dirc[i1];
		if (rn >= 0 && rn < n && cn >= 0 && cn < m && hei[r][c] > hei[rn][cn])
			dfs(rn, cn, fla);
	}
}
int fla = 0;
void f(int la, int sta)
{
	if (sta > mu || la == vpa.size() - 1)
		return;
	int mlt = ml;
	for (auto i1 = la + 1; i1 < vpa.size(); i1++)//remain
	{
		if (bm[0][vpa[i1]])
			continue;
		bool b1 = true;
		dfs(0, vpa[i1], ++fla);
		for (auto i2 = 0; i2 < m - 1; i2++)
			if (!bm[n - 1][i2] && bm[n - 1][i2 + 1])
				b1 = false;
		int flat = fla;
		lml = min(lml, ml);
		if (!ml)
		{
			mu = sta;
			ans = 1;
		}
		vus.push_back(i1);
		if (sta < mu - 1 && b1)
			f(i1, sta + 1);
		vus.pop_back();
		for (auto i1 = 0; i1 < n; i1++)
			for (auto i2 = 0; i2 < m; i2++)
				if (bm[i1][i2] == flat)
					bm[i1][i2] = 0;
		ml = mlt;
		if (!b1)
			return;
	}
}
int main()
{
	cin >> n >> m;
	lml = ml = m;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			cin >> hei[i1][i2];
	if (hei[0][0] >= hei[0][1])
		vpa.push_back(0);
	for (auto i1 = 1; i1 < m - 1; i1++)
		if (hei[0][i1] >= hei[0][i1 - 1] && hei[0][i1] >= hei[0][i1 + 1])
			vpa.push_back(i1++);
	if (hei[0][m - 1] >= hei[0][m - 2])
		vpa.push_back(m - 1);
	mu = vpa.size() + 1;
	f(-1, 1);
	cout << ans << endl;
	if (ans)
		cout << mu << endl;
	else
		cout << lml << endl;
	system("pause");
	return 0;
}