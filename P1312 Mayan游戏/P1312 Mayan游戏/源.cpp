#include <iostream>
#include <vector>

#define MAS 15
using namespace::std;

int n = 0;

int mats[7][7][5] = { 0 };
int ans[5][3] = { 0 };
int dirc[2] = { -1, 1 };
int color[MAS] = { 0 };

inline void swap(int& x, int& y)
{
	int c = x;
	x = y;
	y = c;
}

bool drop(int sta)
{
	bool b1 = false;
	for (auto i1 = 0; i1 < 5; i1++)
		for (auto i2 = 1; i2 < 7; i2++)
			if (mats[sta][i2][i1])
				while (!mats[sta][i2 - 1][i1])
				{
					b1 = true;
					mats[sta][i2 - 1][i1] = mats[sta][i2][i1];
					mats[sta][i2--][i1] = 0;
				}
	return b1;
}
void clear(int sta)
{
	vector<int> vc;
	for (auto i1 = 0; i1 < 5; i1++)
		for (auto i2 = 0; i2 < 5; i2++)
			if (mats[sta][i2 + 2] != 0 && mats[sta][i2][i1] == mats[sta][i2 + 1][i1] && mats[sta][i2][i1] == mats[sta][i2 + 2][i1]) //remain...
			{
				vc.push_back(i2 * 100 + i1);
				vc.push_back(i2 * 100 + i1 + 100);
				vc.push_back(i2 * 100 + i1 + 200);
			}
	for (auto i1 = 0; i1 < 7; i1++)
		for (auto i2 = 0; i2 < 3; i2++)
			if (mats[sta][i1][i2] != 0 && mats[sta][i1][i2] == mats[sta][i1][i2 + 1] && mats[sta][i1][i2] == mats[sta][i1][i2 + 2])
			{
				vc.push_back(i1 * 100 + i2);
				vc.push_back(i1 * 100 + i2 + 1);
				vc.push_back(i1 * 100 + i2 + 2);
			}
	for (auto& i : vc)
		mats[sta][i / 100][i % 100] = 0;
}
void moveit(int r, int c, int dir, int sta)
{
	for (auto i4 = 0; i4 < 5; i4++)
		for (auto i5 = 0; i5 < 7; i5++)
			mats[sta][i5][i4] = mats[sta - 1][i5][i4];
	drop(sta);
	do
	{
		clear(sta);
	} while (drop(sta));
}
void dfs(const int n, const int sta)
{
	if (sta == 1)
	{
		for (auto i1 = 6; i1 > -1; i1--)
		{
			for (auto i2 = 0; i2 < 5; i2++)
				cout << mats[sta][i1][i2] << ' ';
			cout << endl;
		}
		cout << sta << endl;
		system("pause");
	}
	for (auto& i1 : color)
		i1 = 0;
	for (auto i1 = 0; i1 < 5; i1++)
		for (auto i2 = 0; i2 < 7 && mats[sta][i2][i1]; i2++)
			color[mats[sta][i2][i1]]++;
	for (auto i1 : color)
		if (i1 >= 1 && i1 < 3)
			return;
	if (sta == n)
	{
		for (auto i4 = 0; i4 < 5; i4++)
		{
			if (mats[0][i4] != 0)
				return;
		}
		for (auto i5 = 0; i5 < n; i5++)
			cout << ans[i5][0] << ' ' << ans[i5][1] << ' ' << ans[i5][2] << endl;
		system("pause");
		exit(0);
	}
	for (auto i2 = 0; i2 < 5; i2++)
		for (auto i3 = 0; mats[sta][i3][i2] != 0 && i3 < 7; i3++)
		{
			if (i2 + 1 < 5 && mats[sta][i3][i2] != mats[sta][i3][i2 + 1])
			{
				ans[sta][0] = i2, ans[sta][1] = i3, ans[sta][2] = 1;
				swap(mats[sta][i3][i2], mats[sta][i3][i2 + 1]);
				moveit(i3, i2, 1, sta + 1);
				dfs(n, sta + 1);
				swap(mats[sta][i3][i2], mats[sta][i3][i2 + 1]);
			}
			if (i2 - 1 > 0 && !mats[sta][i3][i2 - 1])
			{
				ans[sta][0] = i2, ans[sta][1] = i3, ans[sta][2] = -1;
				swap(mats[sta][i3][i2], mats[sta][i3][i2 - 1]);
				moveit(i3, i2, -1,sta + 1);
				dfs(n, sta + 1);
				swap(mats[sta][i3][i2], mats[sta][i3][i2 - 1]);
			}
		}
}
int main()
{
	cin >> n;
	for (auto i1 = 0; i1 < 5; i1++)
	{
		int c = 0;
		int ic = 0;
		while (cin >> c)
		{
			if (c == 0)
				break;
			mats[0][ic++][i1] = c;
		}
	}
	dfs(n, 0);
	cout << "-1";
	system("pause");
	return 0;
}