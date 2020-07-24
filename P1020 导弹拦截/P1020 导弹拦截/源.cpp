#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

int main()
{
	vector<int> v;
	int x = 0;
	while (cin >> x)
		v.push_back(x);
	vector<int> vfo(1, *v.begin());
	for (auto i1 = v.begin() + 1; i1 < v.end(); i1++)
		if (*i1 <= *vfo.rbegin())
			vfo.push_back(*i1);
		else
			*upper_bound(vfo.begin(), vfo.end(), *i1, greater<int>()) = *i1;
	cout << vfo.size() << endl;
	vector<int> vfm(1, *v.begin());
	for (auto i1 = v.begin() + 1; i1 < v.end(); i1++)
		if (*i1 > *vfm.rbegin())
			vfm.push_back(*i1);
		else
			*lower_bound(vfm.begin(), vfm.end(), *i1) = *i1;
	cout << vfm.size() << endl;
	return 0;
}