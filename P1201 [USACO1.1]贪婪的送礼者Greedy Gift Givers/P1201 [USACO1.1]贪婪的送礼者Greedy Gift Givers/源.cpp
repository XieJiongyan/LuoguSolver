#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace::std;

int gvm[10][10] = { 0 };

int main()
{
	map<string, int> ma;
	int n = 0;
	cin >> n;
	vector<string> v;
	for (auto i1 = 0; i1 < n; i1++)
	{
		string s;
		cin >> s;
		v.push_back(s);
		ma[s] = i1;
	}
	for (auto i1 = 0; i1 < n; i1++)
	{
		string s;
		cin >> s;
		int m = 0, n2 = 0;
		cin >> m >> n2;
		if (n2 == 0)
			continue;
		int pg = ma[s];
		int gm = m / n2;
		for (auto i2 = 0; i2 < n2; i2++)
		{
			cin >> s;
			gvm[pg][ma[s]] -= gm;
			gvm[ma[s]][pg] += gm;
		}
	}
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
	{
		cout << *i1 << ' ';
		int x = ma[*i1];
		int mon = 0;
		for (auto i2 = 0; i2 < n; i2++)
			mon += gvm[x][i2];
		cout << mon << endl;
	}
	system("pause");
	return 0;
}