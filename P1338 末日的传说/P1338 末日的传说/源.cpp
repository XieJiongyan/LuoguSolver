#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	long long m = 0, n = 0;
	cin >> n >> m;
	vector<bool> vb(n, true);
	for (auto i1 = 0; i1 < n; i1++)
		if (m <= (n - 1 - i1) * (n - 2 - i1) / 2)
		{
			cout << i1 + 1 << ' ';
			vb[i1] = false;
		}
		else
		{
			cout << m - ((n - 1 - i1) * (n - 2 - i1) / 2) + i1 + 1 << ' ';
			vb[m - ((n - 1 - i1) * (n - 2 - i1) / 2) + i1] = false;
			break;
		}
	for (auto i1 = vb.rbegin(); i1 < vb.rend(); i1++)
		if (*i1)
			cout << vb.rend() - i1 << ' ';
	system("pause");
	return 0;
}