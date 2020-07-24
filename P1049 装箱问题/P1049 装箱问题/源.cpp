#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

int main()
{
	int n = 0, x = 0;
	cin >> x >> n;
	vector<bool> v(x + 1, false);
	*v.begin() = true;
	int in1;
	for (auto i1 = 0; i1 < n; i1++)
	{
		cin >> in1;
		for (auto i2 = x - 1; i2 > in1 - 1; i2--)
			if (!v[i2] && v[i2 - in1])
				v[i2] = true;
	}
	cout <<(find(v.rbegin(), v.rend(), true) - v.rbegin()) << endl;
	return 0;
}