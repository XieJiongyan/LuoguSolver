#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

struct St
{
	long l;
	long r;
	bool operator<(St);
};

bool St::operator<(St st)
{
	if (min(r, st.l) != min(st.r, l))
		return min(r, st.l) > min(st.r, l);
	else if (l != st.l)
		return l < st.l;
	else
		return r < st.r;
}

int main()
{
	int n = 0;
	cin >> n;
	for (auto i1 = 0; i1 < n; i1++)
	{
		long m = 0;
		cin >> m;
		vector<St> v(m);
		for (auto& i : v)
			cin >> i.l >> i.r;
		sort(v.begin(), v.end());
		long x = 0;
		long c = 0;
		for (auto& i : v)
		{
			x += i.l;
			c = max(x + i.r, c + i.r);
		}
		cout << c << endl;
	}
	system("pause");
	return 0;
}