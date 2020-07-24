#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

#define MAXLONGLONG 0xffffffffffffffff
using namespace::std;

struct Int128
{
	unsigned long long hp;
	unsigned long long lp;
	Int128() : hp(0), lp(0) {};
	Int128(int x) : hp(0), lp(x) {};
	Int128(const Int128& in) : hp(in.hp), lp(in.lp) {};
	Int128& operator=(const Int128& in) 
	{
		hp = in.hp; lp = in.lp;
		return *this;
	}
	Int128 operator+(Int128);
	friend Int128 cal(long long mu, long long de);
	friend ostream& operator<<(ostream&, Int128);
	bool operator<(const Int128&) const;
	Int128 operator/(int);
	int operator%(int);
};
Int128 Int128::operator/(int div)
{
	Int128 rev(*this);
	int rem = (rev.hp % div) * 6 + rev.lp % div;
	rev.lp = rev.lp / div + rev.hp % div * (MAXLONGLONG / div);
	rev.hp /= div;
	rev.lp += rem / div;
	return rev;
}
int Int128::operator%(int div)
{
	return ((hp % div) * 6 + lp % div) % div;
}
bool Int128::operator<(const Int128& in) const
{
	if (hp < in.hp)
		return true;
	else if (hp == in.hp)
		return lp < in.lp;
	else
		return false;
}
#define FL32 0x00000000ffffffff
Int128 Int128::operator+(Int128 in)
{
	Int128 rev;
	rev.hp = hp + in.hp + (((lp >> 32) + (in.lp >> 32)) >> 32);
	rev.lp = (((((lp& FL32) + (in.lp&FL32)) >> 32) + (lp >> 32) +(in.lp >> 32)) << 32) + (((lp & FL32) + (in.lp & FL32)) & FL32);
	return rev;
}
Int128 cal(long long mu, long long de)
{
	Int128 rev;
	rev.hp = de > 64 ? mu << de - 64 : mu >> 64 - de;
	rev.lp = mu << de;
	return rev;
}
ostream& operator<<(ostream& os, Int128 in)
{
	if (in.hp == 0 && in.lp == 0)
	{
		os << 0;
		return os;
	}
	stack<int> ou;
	while (in.hp != 0 || in.lp != 0)
	{
		ou.push(in % 10);
		in = in / 10;
	}
	while (!ou.empty())
	{
		os << ou.top();
		ou.pop();
	}
	return os;
}
int mat[80][80] = { 0 };
Int128 dp[80][80][81] = { 0 };

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			cin >> mat[i1][i2];
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = m - 1; i2 >= 0; i2--)
			for (auto i3 = 0; i3 + i2 < m + 1; i3++)
			{
				if (i3 >= 1)
					dp[i1][i3][i2 + i3] = max(dp[i1][i3][i2 + i3], dp[i1][i3 - 1][i2 + i3] + cal(mat[i1][i3 - 1], m - i2));
				if (i3 + i2 < m)
				{
					dp[i1][i3][i2 + i3] = max(dp[i1][i3][i2 + i3], dp[i1][i3][i2 + i3 + 1] + cal(mat[i1][i2 + i3], m - i2));
				}
			}
	Int128 ans = 0;
	for (auto i1 = 0; i1 < n; i1++)
	{
		Int128 thm = 0;
		for (auto i2 = 0; i2 < m; i2++)
			thm = max(thm, dp[i1][i2][i2]);
		ans = thm + ans;
	}
	cout << ans << endl;
	return 0;
}