#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	int n = 0;
	cin >> n;
	vector<long> v(n);
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
		cin >> *i1;
	auto ll = 0;
	bool b1 = true;
	long long ans = 0;
	for (auto i1 = v.begin() + 1; i1 < v.end(); i1++)
	{
		if (!b1 && (*i1 >= *(i1 - 1)))
		{
			ll = *(i1 - 1);
			b1 = true;
		}
		if (b1 && (*i1 < *(i1 - 1)))
		{
			ans += *(i1 - 1) - ll;
			b1 = false;
		}
		if (b1 && i1 == v.end() - 1)
			ans += *i1 - ll;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}