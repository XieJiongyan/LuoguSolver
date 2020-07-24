#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

struct St
{
	long price;
	long imp;
	long bel;
	long it;
	bool operator<(St);
};

bool St::operator<(St st)
{
	if (bel != 0 && st.bel == 0)
		return bel < st.it;
	if (bel == 0 && st.bel != 0)
		return st.bel >= it;
	if (bel == 0 && st.bel == 0)
		return it < st.it;
	else
		return bel < st.bel;
}

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	vector<St> vst(n);
	for (auto i1 = vst.begin(); i1 < vst.end(); i1++)
	{
		cin >> i1->price >> i1->imp >> i1->bel;
		i1->it = i1 - vst.begin() + 1;
	}
	sort(vst.begin(), vst.end());
	vector<long> vans(m / 10 + 1, 0);
	for (auto i1 = vst.begin(); i1 < vst.end(); ++i1)
	{
		vector<St> vstc;
		vstc.push_back(*i1);
		while (i1 + 1 < vst.end() && (i1 + 1)->bel == vstc.begin()->it)
		{
			i1++;
			vstc.push_back(*i1);
		}
		vector<long> vp;
		vector<long> vip;
		for (auto i2 = 0; i2 < 1 << vstc.size() - 1; i2++)
		{
			long price = vstc.begin()->price;
			long imp = vstc.begin()->price * vstc.begin()->imp;
			for (auto i3 = 0; i3 < vstc.size() - 1; i3++)
			{
				if (i2 & 1 << i3)
				{
					price += vstc[i3 + 1].price;
					imp += vstc[i3 + 1].price * vstc[i3 + 1].imp;
				}
			}
			bool b1 = true;
			if (!vp.empty())
				for (auto i3 = vp.begin(); i3 < vp.end(); ++i3)
					if (*i3 * 10 == price)
					{
						b1 = false;
						*(vip.begin() + (i3 - vp.begin())) = max(imp / 10, *(vip.begin() + (i3 - vp.begin())));
					}
			if (b1)
			{
				vp.push_back(price / 10);
				vip.push_back(imp / 10);
			}
		}
		for (auto i2 = m / 10; i2 >= vp[0]; i2--)
			for (auto i3 = 0; i3 < vp.size(); i3++)
				if (i2 >= vp[i3])
					vans[i2] = max(vans[i2], vans[i2 - vp[i3]] + vip[i3]);
	}
	cout << vans[m / 10] * 10 << endl;
	system("pause");
	return 0;
}