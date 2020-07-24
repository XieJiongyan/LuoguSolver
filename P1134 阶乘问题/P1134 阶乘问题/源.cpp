#include <iostream>

using namespace::std;

const long long mod = static_cast<long long>(5e9);

int main() {
	long long n = 0;
	cin >> n;
	long long ans = 1;
	for (long long i1 = 1; i1 < n + 1; i1++) {
		ans *= i1;
		while (ans % 10 == 0)
			ans /= 10;
		ans = ans % mod;
	}
	cout << ans % 10 << endl;
	return 0;
}