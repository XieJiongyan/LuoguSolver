#include <iostream>

using namespace::std;

int main() {
	int n = 0;
	cin >> n;
	for (auto i1 = 0; i1 < n; i1++) {
		int a = 0, b = 0;
		cin >> a >> b;
		if (a > b) a ^= b ^= a ^= b;
		int gea = a, geb = b;
		while (geb % gea != 0) {
			geb %= gea;
			gea ^= geb ^= gea ^= geb;
		}
		a /= gea, b /= gea;
		bool stw = true;
		if (b == a || b >= 2 * a) stw = true;
		else while (b % a != 0) {
			b %= a;
			a ^= b ^= a ^= b;
			stw = !stw;
			if (b > 2 * a) break;
		}
		switch (stw) {
		case true: cout << "Stan wins" << endl;
			break;
		case false: cout << "Ollie wins" << endl;
			break;
		}
	}
	return 0;
}