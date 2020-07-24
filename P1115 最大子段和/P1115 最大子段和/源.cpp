#include <iostream>
#include <algorithm>

using namespace::std;

int arr[200000] = { 0 };

long f(int il, int ir)
{
	if (il == ir - 1)
		return arr[il];
	else
	{
		long mil = arr[(il + ir) / 2 - 1], mir = arr[(il + ir) / 2];
		long milc = 0, mirc = 0;
		for (auto i1 = (il + ir) / 2 - 1; i1 >= il; i1--)
		{
			milc += arr[i1];
			if (milc > mil)
				mil = milc;
		}
		for (auto i1 = (il + ir) / 2; i1 < ir; i1++)
		{
			mirc += arr[i1];
			if (mir < mirc)
				mir = mirc;
		}
		long x = max(max(mil, mir), mil + mir);
		return max(max(f(il, (il + ir) / 2), f((il + ir) / 2, ir)), x);
	}
}

int main()
{
	int n = 0;
	cin >> n;
	for (auto i1 = 0; i1 < n; i1++)
		cin >> arr[i1];
	cout << f(0, n) << endl;
	system("pause");
	return 0;
}