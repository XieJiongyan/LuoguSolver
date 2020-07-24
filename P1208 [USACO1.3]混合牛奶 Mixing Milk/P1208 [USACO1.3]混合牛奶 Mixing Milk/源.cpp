#include <iostream>
#include <vector>

#define ma 2000

using namespace::std;

int main()
{
	long n, m;
	cin >> n >> m;
	vector<long> va(m);
	vector<long> vp(m);
	for (auto i = 0; i < m; ++i)
		cin >> va[i] >> vp[i];
	long mon = 0;
	while (n > 0)
	{
		long lea = ma;
		long ile = 0;
		for (auto i = 0; i < m; ++i)
			if (va[i] < lea)
			{
				lea = va[i];
				ile = i;
			}
		if (vp[ile] < n)
		{
			n -= vp[ile];
			mon += lea * vp[ile];
		}
		else
		{
			mon += n * lea;
			n = 0;
		}
		va[ile] = ma;
	}
	cout << mon;
	system("pause");
	return 0;
}