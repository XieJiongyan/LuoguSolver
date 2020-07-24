#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace::std;

int main() {
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (auto& i1 : v)	cin >> i1;
	array<int, 2> arr = {};
	arr[0] = find(v.begin(), v.end(), 0) - v.begin();
	arr[1] = find(v.rbegin(), v.rend(), 0) - v.rbegin();
	bool ans = false;
	for (auto i1 : arr) if (i1 % 2 == 1) ans = true;
	switch (ans) {
	case true:
		cout << "YES" << endl;
		break;
	case false:
		cout << "NO" << endl;
		break;
	}
	return 0;
}
