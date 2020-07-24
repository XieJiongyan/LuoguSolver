#include <iostream>
#include <string>
#include <algorithm>

using namespace::std;

long slr[20000][2] = { 0 };
int main()
{
	int n = 0;
	cin >> n;
	string s;
	cin >> s;
	for (auto i1 = 0; i1 < n - 1; i1++)
		s.push_back(s[i1]);
	slr[0][0] = 1;
	int il = 0;
	int iw = s[0] == 'w' ? 0 : -1;
	char cf = s[0];
	for (auto i1 = 1; i1 < n * 2 - 1; i1++)
	{
		if (cf == 'w' && s[i1] != cf)
		{
			cf = s[i1];
			slr[i1][0] = slr[i1 - 1][0] + 1;
		}
		else if (cf == 'w')
			slr[i1][0] = slr[i1 - 1][0] + 1;
		else if (s[i1] != cf && s[i1] != 'w')
		{
			if (iw != -1)
				slr[i1][0] = i1 - iw + 1;
			else
				slr[i1][0] = 1;
			slr[il][1] = i1 - il;
			il = i1;
			cf = s[i1];
		}
		else
			slr[i1][0] = slr[i1 - 1][0] + 1;
		if ((iw == -1) && s[i1] == 'w')
			iw = i1;
		if (s[i1] != 'w')
			iw = -1;
	}
	long ans = 0;
	for (auto i1 = 0; i1 < n * 2 - 1 - 1; i1++)
		ans = max(ans, slr[i1][0] + slr[i1 + 1][1]);
	cout << min(ans, static_cast<long>(n));
	system("pause");
	return 0;
}