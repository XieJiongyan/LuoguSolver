#include <iostream>
#include <vector>
#define MO 100003
using namespace::std;

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	n++;
	vector<long> v(n, 0);
	*v.begin() = 1;
	for(auto i1= v.begin() + 1; i1 < v.end(); ++i1)
		for (auto i2 = i1 - v.begin() > k ? i1 - k : v.begin(); i2 < i1; ++i2)
		{
			*i1 += *i2;
			if (*i1 >= MO)
				*i1 %= MO;
		}
	cout << *v.rbegin();
	system("pause");
	return 0;
}