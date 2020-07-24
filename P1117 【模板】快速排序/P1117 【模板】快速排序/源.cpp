#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

vector<long> v;

void qsort(long iof, long ioe)
{
	if (iof == ioe || iof > ioe)
		return;
	long ia = iof, ib = ioe;
	long x = v[(iof + ioe) / 2];
	while (ia < ib)
	{
		for (; ia < ib; ib--)
		{
			if (v[ib] < x)
			{
				v[ia] = v[ib];
				v[ib] = x;
				break;
			}
		}
		for (; ia < ib; ia++)
		{
			if (v[ia] > x)
			{
				v[ib] = v[ia];
				v[ia] = x;
				break;
			}
		}
	}
	if (iof < ia - 1)
		qsort(iof, ia);
	if (ia + 1 < ioe)
		qsort(ia + 1, ioe);
}
int main()
{
	int n = 0;
	cin >> n;
	v.resize(n);
	for (auto i = v.begin(); i < v.end(); ++i)
		cin >> *i;
	sort(v.begin(), v.end());
	for (auto i = v.begin(); i < v.end(); i++)
		cout << *i << ' ';
	system("pause");
	return 0;
}