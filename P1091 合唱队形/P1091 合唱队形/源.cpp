#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
	int n = 0;
	cin >> n;
	vector<long> v(n, 0);
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
		cin >> *i1;
	vector<long> vl(n, 1);
	vector<long> vr(n, 1);
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
	{
		long mal = 1;
		for (auto i2 = v.begin(); i2 < i1; i2++)
			if (*i1 > *i2)
				mal = max(mal, vl[i2 - v.begin()] + 1);
		vl[i1 - v.begin()] = mal;
	}
	for (auto i1 = v.rbegin(); i1 < v.rend(); i1++)
	{
		long mal = 1;
		for (auto i2 = v.rbegin(); i2 < i1; i2++)
			if (*i1 > *i2)
				mal = max(mal, vr[i2 - v.rbegin()] + 1);
		vr[i1 - v.rbegin()] = mal;
	}
	for (auto i1 = 0; i1 < n; i1++)
		vl[i1] += vr[n - i1 - 1];
	cout << n - *max_element(vl.begin(), vl.end()) + 1 << endl;
	system("pause");
	return 0;
}