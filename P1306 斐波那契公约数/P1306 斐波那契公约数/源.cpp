#include <iostream>
#include <algorithm>

using namespace::std;

constexpr long long mod = 100000000;

struct mat {
	long long a11, a12, a21, a22;
};
struct vec {
	long long v1, v2;
};
long long fibonacci(long long x) {
	mat pon;
	pon.a11 = 1, pon.a12 = 1, pon.a21 = 1, pon.a22 = 0;
	vec ans;
	ans.v1 = 0, ans.v2 = 1;
	for (; x > 0; x >>= 1) {
		if (x & 1) {
			long long an1 = ans.v1;
			ans.v1 = (pon.a11 * ans.v1 + pon.a12 * ans.v2) % mod;
			ans.v2 = (pon.a21 * an1 + pon.a22 * ans.v2) % mod;
		}
		long long p11 = pon.a11, p12 = pon.a12, p21 = pon.a21, p22 = pon.a22;
		pon.a11 = (p11 * p11 + p12 * p21) % mod;
		pon.a12 = (p11 * p12 + p12 * p22) % mod;
		pon.a21 = (p21 * p11 + p22 * p21) % mod;
		pon.a22 = (p21 * p12 + p22 * p22) % mod;
	}
	return ans.v1;
}
int main() {
	//int de = 0;
	//cin >> de;
	//for (auto i1 = 0; i1 < de; i1++) cout << fibonacci(i1 + 1) << endl;
	long long n = 0, m = 0;
	cin >> n >> m;
	if (n < m) n ^= m ^= n ^= m;
	while (n % m) {
		n %= m;
		n ^= m ^= n ^= m;
	}
	cout << fibonacci(m) << endl;
	return 0;
}