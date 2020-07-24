#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<long> v(n);
	for (auto i = v.begin(); i < v.end(); i++)
		cin >> *i;
	int mx = 0;
	int ans = 0;
	for (auto i = v.begin(); i < v.end(); i++)
	{
		if (mx + *i > m)
		{
			ans++;
			mx = *i;
		}
		else
			mx += *i;
	}
	if (mx >= 0)
		ans++;
	cout << ans << endl;
	system("pause");
	return 0;
}