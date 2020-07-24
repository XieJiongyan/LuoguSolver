#include <iostream>
#include <vector>

using namespace::std;

long ans = 0;
int n = 0;
vector<long> v;
bool b1 = true;

long mac(long l, long u)
{
	long ans = 1;
	for (auto i1 = u + 1; i1 < l + 1; i1++)
		ans *= i1;
	for (auto i1 = 1; i1 < l - u + 1; i1++)
		ans /= i1;
	return ans;
}

void dfs(int st, long long hud)
{
	if (ans < 0 || !b1)
		return;
	if (st == n && ans == 0)
	{
		b1 = false;
		return;
	}
	for (auto i1 = 0; i1 < n; i1++)
		if (!((hud >> i1) & 1))
		{
			v.push_back(i1 + 1);
			ans -= (i1 + 1) * mac(n - 1, st);
			dfs(st + 1, hud + (1 << i1));
			if (!b1)
				return;
			ans += (i1 + 1) * mac(n - 1, st);
			v.pop_back();
		}
}

int main()
{
	cin >> n >> ans;
	dfs(0, 0);
	if (!b1)
		for (auto i1 = v.begin(); i1 < v.end(); i1++)
			cout << *i1 << ' ';
	system("pause");
	return 0;
}