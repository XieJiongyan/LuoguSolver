#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	long long n = 0, k = 0;
	cin >> n >> k;
	vector<long long> v;
	while (n > 0)
	{
		v.push_back(n & -n);
		n -= n & -n;
	}
	if (v.size() <= k)
	{
		cout << '0' << endl;
		return 0;
	}
	long long x = *(v.rbegin() + k - 1);
	long long y = 0;
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
	{
		if (*i1 == x)
			break;
		y += *i1;
	}
	cout << x - y << endl;
	system("pause");
	return 0;
}