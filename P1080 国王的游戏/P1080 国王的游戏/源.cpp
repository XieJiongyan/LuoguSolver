#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

struct St
{
	long mul;
	long div;
	bool operator<(St);
};

bool St::operator<(St st)
{
	return mul * div < st.mul * st.div;
}

int ans[25000] = { 0 }, ansc[25000] = { 1 }, man[25000] = { 1 };
long sac = 1, san = 1;
long long muv = 0;

int main()
{
	long n = 0;
	cin >> n;
	vector<St> vst(n + 1);
	for (auto i1 = vst.begin(); i1 < vst.end(); i1++)
		cin >> i1->mul >> i1->div;
	sort(vst.begin() + 1, vst.end());
	for (auto i1 = vst.begin() + 1; i1 < vst.end(); i1++)
	{
		muv = 0;
		for (auto i3 = 0; i3 < sac; i3++)
		{
			ansc[i3] = ansc[i3] * (i1 - 1)->mul + muv;
			muv = ansc[i3] / 10;
			ansc[i3] %= 10;
		}
		while (muv)
		{
			ansc[sac++] = muv % 10;
			muv /= 10;
		}
		for (auto i2 = 0; i2 < sac; i2++)
			man[i2] = ansc[i2];
		for (auto i2 = sac - 1; i2 > -1; i2--)
		{
			muv = muv * 10 + man[i2];
			man[i2] = muv / i1->div;
			muv %= i1->div;
		}
		bool b1 = false;
		for (auto i2 = max(sac, san) - 1; i2 > -1; i2--)
			if (ans[i2] < man[i2])
			{
				b1 = true;
				break;
			}
			else if (ans[i2] > man[i2])
			{
				b1 = false;
				break;
			}
		if (b1)
		{
			san = sac;
			for (auto i1 = 0; i1 < san; i1++)
				ans[i1] = man[i1];
		}
	}
	bool b2 = true;
	for (auto i1 = san - 1; i1 > -1; i1--)
		if (b2 && ans[i1] == 0)
			continue;
		else
		{
			b2 = false;
			cout << ans[i1];
		}
	system("pause");
	return 0;
}
