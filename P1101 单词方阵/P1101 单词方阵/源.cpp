#include <iostream>
#include <string>

using namespace::std;

int dirx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int diry[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
string s = "yizhong";

int main()
{
	char mat[100][100] = { 0 };
	char mata[100][100] = { '*' };
	int n = 0;
	cin >> n;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; ++i2)
			mata[i1][i2] = '*';
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> mat[i1][i2];
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
		{
			if (mat[i1][i2] == 'y')
				for (auto i3 = 0; i3 < 8; i3++)
				{
					if (i1 + 6 * dirx[i3] >= 0 && i1 + 6 * dirx[i3] < n && i2 + 6 * diry[i3] >= 0 && i2 + 6 * diry[i3] < n)
					{
						bool b1 = true;
						for (auto i4 = 1; i4 < 7; ++i4)
							if (mat[i1 + i4 * dirx[i3]][i2 + i4 * diry[i3]] != s[i4])
							{
								b1 = false;
								break;
							}
						if (!b1)
							continue;
						for (auto i4 = 0; i4 < 7; ++i4)
							mata[i1 + i4 * dirx[i3]][i2 + i4 * diry[i3]] = s[i4];
					}
				}
		}
	for (auto i1 = 0; i1 < n; i1++)
	{
		for (auto i2 = 0; i2 < n; i2++)
			cout << mata[i1][i2];
		cout << endl;
	}
	system("pause");
	return 0;
}