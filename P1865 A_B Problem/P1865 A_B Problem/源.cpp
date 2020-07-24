#include <iostream>
#include "Primernum.h"
#include <vector>

#define MAX 10000001
long bit[MAX] = { 0 };

inline int lowbit(int x)
{
	return x & (-x);
}

void add(long ip, long num)
{
	for (long i = ip; i <= MAX; i += lowbit(i))
		bit[i] += num;
}

int query(int u)
{
	int res = 0;
	for (int i = u; i > 0; i -= lowbit(i))
	{
		res += bit[i];
	}
	return res;
}
using namespace::std;

int main()
{
	long n = 0, m = 0;
	cin >> n >> m;
	primernum.generate(m);
	for (auto i1 = primernum.all.begin(); i1 < primernum.all.end(); ++i1)
		add(*i1, 1);
	vector<long> vl(n);
	vector<long> vr(n);
	for (auto i1 = vl.begin(), ii1 = vr.begin(); i1 < vl.end(); ++i1, ++ii1)
		cin >> *i1 >> *ii1;
	for (auto i = 0; i < n; ++i)
	{
		long ll = vl[i];
		long lr = vr[i];
		if (ll < 1 || lr < 1 || ll > m || lr > m)
		{
			cout << "Crossing the line" << endl;
			continue;
		}
		cout << query(lr) - query(ll - 1) << endl;
	}
	system("pause");
	return 0;
}
