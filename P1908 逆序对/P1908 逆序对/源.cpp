#include <iostream>
#include <vector>
#include <algorithm>

#define BIT_SIZE 500//112
using namespace::std;

long long bit[BIT_SIZE] = { 0 };

void ins_bit(long long poi, long long nu)
{
	while (poi < BIT_SIZE)
	{
		bit[poi] += nu;
		poi += poi & -poi;
	}
}

long long fin_bit(long long l, long long r)
{
	r--, l--;
	long long rev = 0;
	while (r > 0)
	{
		rev += bit[r];
		r -= r & -r;
	}
	while (l > 0)
	{
		rev -= bit[l];
		l -= l & -l;
	}
	return rev;
}

struct St
{
	long long n;
	long long po;
};

bool cmp1(St st1, St st2)
{
	return st1.n < st2.n;
}

bool cmp2(St st1, St st2)
{
	return st1.po < st2.po;
}

int main()
{
	long long n = 0;
	cin >> n;
	vector<St> v(n);
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
	{
		cin >> i1->n;
		i1->po = i1 - v.begin();
	}
	sort(v.begin(), v.end(), cmp1);
	int nct = 1;
	auto tl = v.begin();
	//for(auto i1 = v.begin() + 1; i1 < v.end(); i1++)
	//	if (i1->n != tl->n || i1 == v.end() - 1)
	//	{
	//		for (auto i2 = tl; i2 < i1; i2++)
	//			i2->n = nct;
	//		nct++;
	//		tl = i1;
	//	}
	sort(v.begin(), v.end(), cmp2);
	long long ans = 0;
	for (auto i1 : v)
	{
		ans += fin_bit(i1.n + 1, BIT_SIZE);
		ins_bit(i1.n, 1);
	}
	cout << ans << endl;
	return 0;
}