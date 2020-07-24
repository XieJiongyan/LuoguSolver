#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
	int n = 0, s = 0;
	int h1 = 0, h = 0;
	cin >> n >> s >> h1 >> h;
	h += h1;
	vector<long> v;
	long lc = 0, vc = 0;
	for (auto i1 = 0; i1 < n; i1++)
	{
		cin >> lc >> vc;
		if (lc <= h)
			v.push_back(vc);
	}
	sort(v.begin(), v.end());
	long ans = 0;
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
	{
		if (s < *i1)
			break;
		else
		{
			s -= *i1;
			ans++;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}