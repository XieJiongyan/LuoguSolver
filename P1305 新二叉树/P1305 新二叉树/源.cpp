#include <iostream>
#include <map>
#include <string>

using namespace::std;

char tre[10000000] = { 0 };

void dlr(int it)
{
	if (tre[it] != 0)
	{
		cout << tre[it];
		dlr(it * 2);
		dlr(it * 2 + 1);
	}
}
int main()
{
	int n = 0;
	cin >> n;
	map<char, long> ma;
	for (auto i1 = 0; i1 < n; i1++)
	{
		string s;
		cin >> s;
		if (ma.find(*s.begin()) == ma.end())
		{
			tre[1] = *s.begin();
			ma[*s.begin()] = 1;
		}
		for (auto i2 = 0; i2 < 2; i2++)
			if (*(s.begin() + 1 + i2) != '*')
			{
				tre[ma[*s.begin()] * 2 + i2] = *(s.begin() + 1 + i2);
				ma[*(s.begin() + 1 + i2)] = ma[*s.begin()] * 2 + i2;
			}
	}
	dlr(1);
	system("pause");
	return 0;
}