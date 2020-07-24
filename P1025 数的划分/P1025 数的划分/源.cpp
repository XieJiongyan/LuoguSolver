#include <iostream>

long f(long, long);

using namespace::std;

int main()
{
	long n, k;
	cin >> n >> k;
	cout << f(n, k) << endl;
	system("pause");
	return 0;
}

long f(long n, long k)
{
	if (k == 2)
		return n / 2;
	else
	{
		long ans = 0;
		for (auto i = 1; i <= n / k; ++i)
			ans += f(n - (i - 1)*(k - 1) - i, k - 1);
		return ans;
	}
}