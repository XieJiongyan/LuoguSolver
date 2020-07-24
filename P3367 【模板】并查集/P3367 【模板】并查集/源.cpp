#include <iostream>
#include <vector>

using namespace::std;

long unf[10001];

long ffi(int x)
{
	if (x == unf[x])
		return x;
	else
		return unf[x] = ffi(unf[x]);
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (auto i1 = 1; i1 < n + 1; i1++)
		unf[i1] = i1;
	for (auto i1 = 0; i1 < m; i1++)
	{
		long l1, l2, l3;
		cin >> l1 >> l2 >> l3;
		switch (l1)
		{
		case 1:
			unf[ffi(l2)] = ffi(l3);
			break;
		case 2:
			if (ffi(l2) == ffi(l3))
				cout << "Y" << endl;
			else
				cout << "N" << endl;
		}
	}
	system("pause");
	return 0;
}