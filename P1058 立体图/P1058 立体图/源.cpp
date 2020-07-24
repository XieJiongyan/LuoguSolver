#include <iostream>
#include <algorithm>

using namespace::std;

char paint[1000][1000] = { 0 };
long hei[50][50];
char fud[6][7] =
{
	{ '+', '-', '-', '-', '+', 0, 0},
	{ '|', ' ', ' ', ' ', '|', '/', 0},
	{ '|', ' ', ' ', ' ', '|', ' ', '+'},
	{ '+', '-', '-', '-', '+', ' ', '|'},
	{ 0, '/', ' ', ' ', ' ', '/', '|'},
	{ 0, 0, '+', '-', '-', '-', '+'}
};
int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	for (auto i1 = m - 1; i1 > -1; i1--)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> hei[i1][i2];
	long rlm = 0;
	long clm = 0;
	for (auto i1 = m - 1; i1 > -1; i1--)
		for (auto i2 = 0; i2 < n; i2++)
			for (auto i3 = 0; i3 < hei[i1][i2]; i3++)
			{
				long rl = i1 * 2 + i3 * 3;
				long cl = i1 * 2 + i2 * 4;
				rlm = max(rl, rlm);
				clm = max(cl, clm);
				for (auto i4 = 0; i4 < 6; i4++)
					for (auto i5 = 0; i5 < 7; i5++)
						if ( fud[i4][i5] != 0)
							paint[rl + i4][cl + i5] = fud[i4][i5];
			}
	for (auto i1 = rlm + 5; i1 > -1; i1--)
	{
		for (auto i2 = 0; i2 < clm + 7; i2++)
			if (paint[i1][i2] == 0)
				cout << '.';
			else
				cout << paint[i1][i2];
		cout << endl;
	}
	system("pause");
	return 0;
}