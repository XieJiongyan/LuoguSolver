#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
	int n = 0;
	cin >> n;
	vector<long> v(n);
	vector<long long> vn(n, 0);
	vector<long long> vw(n, 0);
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
		cin >> *i1;
	for (auto i1 = 0; i1 < n; i1++)
	{
		vector<int> veq;
		vector<int> vla;
		for (auto i2 = 0; i2 < i1; i2++)
			if (v[i1] < v[i2])
			{
				if (vn[i1] < vn[i2])
				{
					vla.clear();
					vn[i1] = vn[i2];
					vla.push_back(i2);
				}
				else if (vn[i1] == vn[i2])
					vla.push_back(i2);
			}
			else if (v[i1] == v[i2])
				veq.push_back(i2);
		vn[i1]++;
		if (vla.empty())
			vw[i1] = 1;
		else
			for (auto i2 = vla.begin(); i2 < vla.end(); i2++)
				vw[i1] += vw[*i2];
		if (!veq.empty())
			for (auto i2 = veq.begin(); i2 < veq.end(); i2++)
				if (vn[i1] == vn[*i2])
					vw[i1] -= vw[*i2];
	}
	int nma = 0;
	long long ans = 0;
	for (auto i1 = 0; i1 < n; i1++)
		if (vn[i1] > nma)
		{
			nma = vn[i1];
			ans = vw[i1];
		}
		else if (vn[i1] == nma)
			ans += vw[i1];
	cout << nma << ' ' << ans << endl;
	system("pause");
	return 0;
}