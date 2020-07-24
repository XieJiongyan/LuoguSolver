#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

int main()
{
	long n = 0;
	cin >> n;
	vector<long> v(n);
	for (auto i = v.begin(); i < v.end(); ++i)
		cin >> *i;
	sort(v.begin(), v.end());
	long ans1 = 0;
	long la = *v.begin();
	for (auto i = v.begin() + 1; i < v.end(); ++i)
		if (*i == la)
		{
			*i = -1;
			n -= 1;
		}
		else
			la = *i;
	cout << n << endl;
	for (auto i = v.begin(); i < v.end(); ++i)
		if (*i != -1)
			cout << *i << ' ';
	system("pause");
	return 0;
}