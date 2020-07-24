#include <iostream>

using namespace::std;

const int p = 10007;

void pqi(int& chv, int x, int y, int m) { // chv = chv * x^y % z
	int d = x;
	for (; y > 0; y >>= 1) {
		if (y & 1)
			chv = (chv * d) % m;
		d = d * d % m;
	}
}
int main() {
	int a = 0, b = 0, k = 0, n = 0, m = 0;
	cin >> a >> b >> k >> n >> m;
	int ans = 1;
	//if (n + m != k) {
	//	cout << 0 << endl;
	//	return 0;
	//}
	for (auto i1 = 0; i1 < n; i1++)
		ans = ans * (k - i1) % p;
	for (auto i1 = 0; i1 < n; i1++)
		pqi(ans, i1 + 1, p - 2, p);
	a %= p, b %= p;
	pqi(ans, b, m, p);
	pqi(ans, a, n, p);
	cout << ans;
	return 0;
}