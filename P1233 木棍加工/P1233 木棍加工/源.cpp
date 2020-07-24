#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	int n = 0;
	cin >> n;
	vector<bool> vb(n, true);
	long al = n;
	vector<long> vx(n, 0);
	vector<long> vy(n, 0);
	for (auto i1 = vx.begin(), ii1 = vy.begin(); i1 < vx.end(); ++i1, ++ii1)
		cin >> *i1 >> *ii1;
	long ya = 10000;
	long ans = 1;
	while (al > 0)
	{
		int in = -1;
		long vm = 0;
		for (auto i1 = 0; i1 < n; ++i1)
			if (vb[i1] && vx[i1] >= vm && vy[i1] <= ya)
			{
				vm = vx[i1];
				in = i1;
			}
		if (in == -1)
		{
			ans++;
			ya = 10000;
		}
		else
		{
			vb[in] = false;
			al--;
			ya = vy[in];
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}