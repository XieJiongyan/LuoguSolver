#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	vector<long> v;
	int iv = 0;
	int ans = 0;
	for (auto i = 0; i < n; ++i)
	{
		long l = 0;
		bool b1 = true;
		cin >> l;
		for (auto i2 = v.begin(); i2 < v.end(); ++i2)
			if (l == *i2)
			{
				
				b1 = false;
				break;
			}
		if (b1)
		{
			ans++;
			if (v.size() < m)
				v.push_back(l);
			else
			{
				v[iv] = l;
				iv++;
				if (iv == m)
					iv = 0;
			}
		}
	}
	cout << ans;
	system("pause");
	return 0;
}