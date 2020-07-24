#include <iostream>
#include <algorithm>

using namespace::std;

constexpr int mod = 20100403;

long long C(int n, int m) {
	m = min(m, n - m);
	long long ans = 1;
	for (auto i1 = n; i1 >= n - m + 1; i1--) ans = ans * i1 % mod;
	for (auto i1 = 1; i1 <= m; i1++) {
		long long mdn = i1;
		for (int x = mod - 2; x > 0; x >>= 1) {
			if (x & 1) ans = ans * mdn % mod;
			if (mdn <= 1) break;
			mdn = mdn * mdn % mod;
		}
	}
	return ans;
}
int main() {
	int n = 0, m = 0;
	cin >> n >> m;
	cout << (C(m + n, m) - C(m + n, m - 1) + mod) % mod << endl;
	return 0;
}