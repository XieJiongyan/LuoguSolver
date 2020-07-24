#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

struct St
{
	int t;
	int l;
	int h;
	bool operator<(St);
};
inline bool St::operator<(St st)
{
	return t < st.t;
}
int main()
{
	int d = 0, g = 0;
	cin >> d >> g;
	vector<int> dp(d, -1);
	dp[0] = 10;
	vector<St> vg(g);
	for (auto& i1 : vg)
		cin >> i1.t >> i1.l >> i1.h;
	sort(vg.begin(), vg.end());
	//int dh = 0;
	//int dl = 0;
	//for (auto i1 = vg.begin(); i1->t <= 351; i1++)
	//	cout <<i1->t << ' '<<  (dh += i1->h) << ' ' << (dl += i1->l) << endl;
	for (auto i1 = vg.rbegin(); i1 < vg.rend() - 1; i1++)
		i1->t -= (i1 + 1)->t;
	int tn = 0;
	for (auto i1 : vg)
	{
		for (auto i2 = dp.rbegin(); i2 < dp.rend(); i2++)
		{
			if (*i2 == -1)
				continue;
			if (*i2 < i1.t)
			{
				if (i2 == dp.rend() - 1)
				{
					cout << tn + *i2 << endl;
					exit(0);
				}
				*i2 = -1;
				continue;
			}
			if (i2 - dp.rbegin() < i1.h)
			{
				cout << tn + i1.t << endl;
				exit(0);
			}
			*i2 -= i1.t;
			*(i2 - i1.h) = max(*i2, *(i2 - i1.h));
			*i2 += i1.l;
		}
		tn += i1.t;
	}
	cout << tn + *dp.begin() << endl;
	return 0;
}