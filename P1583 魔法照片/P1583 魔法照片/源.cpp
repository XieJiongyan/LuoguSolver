#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

struct Cl
{
	long d;
	long w;
	long i;
	bool operator<(Cl);
};

inline bool Cl::operator<(Cl c)
{
	if (w < c.w)
		return true;
	else if (w == c.w)
		return i > c.i;
	else
		return false;
}

struct C2
{
	long i;
	long w;
	bool operator<(C2);
};

inline bool C2::operator<(C2 c)
{
	if (w < c.w)
		return true;
	else if (w == c.w)
		return i > c.i;
	else
		return false;
}
int main()
{
	long n = 0, k = 0;
	cin >> n >> k;
	vector<C2> v(n);
	long e[10] = { 0 };
	for (auto i1 = 0; i1 < 10; ++i1)
		cin >> e[i1];
	for (auto i1 = v.begin(); i1 < v.end(); ++i1)
	{
		cin >> i1->w;
		i1->i = i1 - v.begin() + 1;
	}
	sort(v.rbegin(), v.rend());
	vector<Cl> vc(n);
	for (auto i1 = vc.begin(); i1 < vc.end(); ++i1)
	{
		i1->d = i1 - vc.begin() + 1;
		i1->w = (v.begin() + (i1 - vc.begin()))->w;
		i1->i = (v.begin() + (i1 - vc.begin()))->i;
		i1->w += e[(i1->d - 1) % 10];
	}
	sort(vc.rbegin(), vc.rend());
	for (auto i1 = vc.begin(); i1 < vc.begin() + k; ++i1)
		cout << i1->i << ' ';
	system("pause");
	return 0;
}
