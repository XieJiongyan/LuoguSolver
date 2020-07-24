#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
	int n = 0;
	cin >> n;
	vector<long long> v(n);
	for (auto i = v.begin(); i < v.end(); ++i)
		cin >> *i;
	int ans = 0;
	sort(v.rbegin(), v.rend());
	while (v.size() > 1)
	{
		ans += *v.rbegin() + *(v.rbegin() + 1);
		long x = *v.rbegin() + *(v.rbegin() + 1);
		v.pop_back();
		v.pop_back();
		if (v.empty())
			break;
		else if (x <= *v.rbegin())
		{
			v.push_back(x);
			continue;
		}
		for(auto i = v.begin(); i < v.end(); ++i)
			if (*i < x)
			{
				v.insert(i, x);
				break;
			}
	}
	cout << ans;
	system("pause");
	return 0;
}