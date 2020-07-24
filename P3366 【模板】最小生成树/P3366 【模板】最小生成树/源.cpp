#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

long uni[5001] = { 0 };

long funi(long x)
{
	if (x == uni[x])
		return x;
	else
		return uni[x] = funi(uni[x]);
}

struct Gra
{
	long u;
	long v;
	long w;
	bool operator<(Gra);
};

inline bool Gra::operator<(Gra g)
{
	return w < g.w;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<Gra> vgra(m);
	for (auto i1 = 0; i1 < 5001; i1++)
		uni[i1] = i1;
	for (auto& i1 : vgra)
		cin >> i1.u >> i1.v >> i1.w;
	sort(vgra.begin(), vgra.end());
	long trl = 0;
	long ans = 0;
	for (auto i1 : vgra)
	{
		if (funi(i1.u) == funi(i1.v))
			continue;
		ans += i1.w;
		uni[funi(i1.u)] = funi(i1.v);
		if (++trl == n - 1)
			break;
	}
	cout << ans;
	system("pause");
	return 0;
}