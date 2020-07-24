#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

int main()
{
	long n = 0, l = 0;
	cin >> l >> n;
  if (!n) {
    cout << "0 0" << endl;
    return 0;
  }
	vector<long> v(n);
	for (auto i = v.begin(); i < v.end(); ++i)
		cin >> *i;
	long mi = *min_element(v.begin(), v.end());
	long ma = *max_element(v.begin(), v.end());
	for (auto i = v.begin(); i < v.end(); ++i)
		if (*i > l / 2)
			*i = l +1 - *i;
	cout << *max_element(v.begin(), v.end()) << ' ' << max(l - mi + 1, ma) << endl;
	system("pause");
	return 0;
}