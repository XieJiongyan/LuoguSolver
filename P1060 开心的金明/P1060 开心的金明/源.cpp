#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
	int mon = 0, n = 0;
	cin >> mon >> n;
	vector<long> vm(n);
	vector<long> vp(n);
	for (auto i1 = 0; i1 < n; i1++)
		cin >> vm[i1] >> vp[i1];
	vector<long> va(mon + 1, 0);
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = mon; i2 >= vm[i1]; i2--)
			va[i2] = max(va[i2], va[i2 - vm[i1]] + vm[i1] * vp[i1]);
	cout << va[mon] << endl;
	system("pause");
	return 0;
}