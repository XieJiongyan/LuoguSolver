#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

struct C1
{
	short chi;
	short mth;
	short eng;
	int i;
	bool operator<(C1);
};

inline bool C1::operator<(C1 c)
{
	if (chi + mth + eng < c.chi + c.mth + c.eng)
		return true;
	else if (chi + mth + eng == c.chi + c.mth + c.eng)
		if (chi * 10000 < c.chi * 10000 )
			return true;
		else if (chi * 10000== c.chi * 10000)
			return i > c.i;
		else
			return false;
	else
		return false;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<C1> v(n);
	for (auto i = v.begin(); i < v.end(); ++i)
	{
		i->i = i - v.begin() + 1;
		cin >> i->chi >> i->mth >> i->eng;
	}
	sort(v.rbegin(), v.rend());
	for (auto i = v.begin(); i < v.begin() + 5; ++i)
		cout << i->i << ' ' << i->chi + i->mth + i->eng << endl;
	system("pause");
	return 0;
}