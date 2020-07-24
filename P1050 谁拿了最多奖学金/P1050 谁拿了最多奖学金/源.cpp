#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace::std;

struct C1
{
	string s;
	short sl;
	short sc;
	bool bh;
	bool bw;
	short pap;
	long mon;
	bool operator<(C1);
};

inline bool C1::operator<(C1 c)
{
	return mon < c.mon;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<C1> v(n);
	for (auto i1 = v.begin(); i1 < v.end(); ++i1)
	{
		cin >> i1->s >> i1->sl >> i1->sc;
		char c = 'm';
		cin >> c;
		i1->bh = c == 'Y' ? true : false;
		cin >> c;
		i1->bw = c == 'Y' ? true : false;
		cin >> i1->pap;
		i1->mon = 0;
	}
	for (auto i1 = v.begin(); i1 < v.end(); ++i1)
	{
		if (i1->sl > 80 && i1->pap > 0)
			i1->mon += 8000;
		if (i1->sl > 85 && i1->sc > 80)
			i1->mon += 4000;
		if (i1->sl > 90)
			i1->mon += 2000;
		if (i1->sl > 85 && i1->bw)
			i1->mon += 1000;
		if (i1->sc > 80 && i1->bh)
			i1->mon += 850;
	}
	cout << max_element(v.begin(), v.end())->s << endl;
	cout << max_element(v.begin(), v.end())->mon << endl;
	long amon = 0;
	for (auto i1 = v.begin(); i1 < v.end(); ++i1)
		amon += i1->mon;
	cout << amon;
	system("pause");
	return 0;
}