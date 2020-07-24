#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> v(n);
	for (auto i1 = v.begin(); i1 < v.end(); ++i1)
		*i1 = i1 - v.begin() + 1;
	int iv = 0;
	for (auto i1 = 0; i1 < n; i1++)
	{
		iv = (iv + m - 1) % v.size();
		cout << v[iv] << ' ';
		v.erase(v.begin() + iv);
	}
	system("pause");
	return 0;
}