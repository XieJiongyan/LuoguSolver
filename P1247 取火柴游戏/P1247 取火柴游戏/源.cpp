#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

int main() {
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (auto& i1 : v) cin >> i1;
	int xon = 0;
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
		xon ^= *i1;
	switch (xon) {
	case 0: cout << "lose" << endl;
		break;
	default: {
		auto it1 = v.begin();
		for (auto&& i1 = v.begin(); i1 < v.end(); i1++) if ((*i1 ^ xon) < *i1) {
			it1 = i1;
			break;
		}
		cout << *it1 - (*it1 ^ xon) << ' ' << it1 - v.begin() + 1 << endl;
		for (auto&& i1 = v.begin(); i1 < v.end(); i1++) if (i1 != it1) cout << *i1 << ' ';
		else cout << (*i1 ^ xon) << ' '; }
	}
	return 0;
}