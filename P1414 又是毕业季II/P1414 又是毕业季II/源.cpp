#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int mn[1000001];

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (auto& i1 : v)
		cin >> i1;
	for (auto& i1 : v)
	{
		for (auto i2 = 1; i2 * i2 <= i1; i2++)
			if (i1 % i2 == 0)
			{
				mn[i2]++;
				if (i2 * i2 != i1)
					mn[i1 / i2]++;
			}
	}
	int ima = *max_element(v.begin(), v.end());
	for (auto i1 = 0; i1 < n; i1++)
	{
		while (mn[ima] < i1 + 1)
			ima--;
		cout << ima << endl;
	}
	system("pause");
	return 0;
}