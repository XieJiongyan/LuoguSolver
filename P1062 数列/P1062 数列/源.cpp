#include <iostream>

using namespace::std;

int main()
{
	int k = 0, n = 0;
	cin >> k >> n;
	long long ans = 0;
	long long ansc = 1;
	for (auto i1 = 0; i1 < 15 && n > 0; i1++, n >>= 1)
	{
		if (n & 1)
			ans += ansc;
		ansc *= k;
	}
	cout << ans;
	system("pause");
	return 0;
}