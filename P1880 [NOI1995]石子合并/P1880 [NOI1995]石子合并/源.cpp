#include <iostream>
#include <algorithm>

#define MAXC 202

using namespace::std;

int sec[201][MAXC] = { 0 }; //sec[a][b] means  [a, b)
int bit[MAXC] = { 0 };

void ins_bit(int poi, int x)
{
	do
		bit[poi] += x;
	while ((poi += (poi & -poi)) < MAXC);
}
int look_bit(int l, int r) //[l, r]
{
	int ln = l, rn = r;
	int rev = 0;
	do
		rev += bit[r];
	while ((r -= (r & -r)) > 0);
	l--;
	do
		rev -= bit[l];
	while ((l -= (l & -l)) > 0);
	return rev;
}
int main()
{
	int n = 0;
	cin >> n;
	int x = 0;
	for (auto i1 = 0; i1 < n; i1++)
	{
		cin >> x;
		ins_bit(i1 + 1, x);
		ins_bit(i1 + n + 1, x);
	}
	for (auto i1 = 0; i1 < n + 1; i1++)
		sec[i1][i1 + 1] = 0;
	for (auto i1 = 0; i1 < 2 * n; i1++)
		for (auto i2 = i1 + 2; i2 < 2 * n; i2++)
			sec[i1][i2] = 0x77ffffff;
	for (auto i1 = 2; i1 < n + 1; i1++)
		for (auto i2 = 0; i2 + i1 < 2 * n; i2++)
			for (auto i3 = 1; i3 < i1; i3++)
				sec[i2][i2 + i1] = min(sec[i2][i2 + i1], sec[i2][i2 + i3] + sec[i2 + i3][i2 + i1] + look_bit(i2 + 1, i2 + i1));
	int ans = 0x77fffff;
	for (auto i1 = 0; i1 < n; i1++)
		ans = min(ans, sec[i1][i1 + n]);
	cout << ans << endl;
	for (auto i1 = 0; i1 < n + 1; i1++)
		for (auto i2 = i1 + 2; i2 < 2 * n; i2++)
			sec[i1][i2] = 0;
	for (auto i1 = 2; i1 < n + 1; i1++)
		for (auto i2 = 0; i2 + i1 < 2 * n; i2++)
			for (auto i3 = 1; i3 < i1; i3++)
				sec[i2][i2 + i1] = max(sec[i2][i2 + i1], sec[i2][i2 + i3] + sec[i2 + i3][i2 + i1] + look_bit(i2 + 1, i2 + i1));
	ans = 0;
	for (auto i1 = 0; i1 < n; i1++)
		ans = max(ans, sec[i1][i1 + n]);
	cout << ans << endl;
	return 0;
}