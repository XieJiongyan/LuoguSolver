#include <iostream>
#include <vector>
#include <algorithm>

#define MIT_SIZE (102)
using namespace::std;

int mit[MIT_SIZE];

void ins_mit(int poi, int nu)
{
	while (poi < MIT_SIZE)
	{
		mit[poi] += nu;
		poi += poi & -poi;
	}
}

int fin_mit(int ral, int rar)//[ral, rar)
{
	int rev = 0;
	ral--, rar--;
	while (rar > 0)
	{
		rev += mit[rar];
		rar -= rar & -rar;
	}
	while (ral > 0)
	{
		rev -= mit[ral];
		ral -= ral & -ral;
	}
	return rev;
}

int dp[2][51][9][52]; //0 means min, 1 means max

int main()
{

	int n = 0, m = 0;
	int ansi = 0x77ffffff, ansa = 0, ansc = 0;
	cin >> n >> m;
	int x = 0;
	for (auto i1 = 0; i1 < n; i1++)
	{
		cin >> x;
		ins_mit(i1 + 1, x);
		ins_mit(i1 + 1 + n, x);
	}
	for (auto i1 = 1; i1 < n + 1; i1++)
		for (auto i2 = 1; i2 < n + 2; i2++)
		{
			dp[0][i1][0][i1 + i2] = (fin_mit(i1, i1 + i2) + 1000000) % 10;
			dp[1][i1][0][i1 + i2] = (fin_mit(i1, i1 + i2) + 1000000) % 10;
		}
	for (auto i1 = 1; i1 < n + 1; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			for (auto i3 = 2; i3 < n + 2; i3++)//[i1, i1 + i3)
				for (auto i4 = 1; i4 < i3; i4++) // i1 + i4 belongs to (i1, i1 + i3)
				{
					dp[0][i1][i2][i1 + i3] = min(dp[0][i1][i2][i1 + i3], dp[0][i1][i2][i1 + i4] * ((fin_mit(i1 + i4, i1 + i3) + 1000000) % 10));
					dp[1][i1][i2][i1 + i3] = max(dp[1][i1][i2][i1 + i3], dp[1][i1][i2][i1 + i4] * ((fin_mit(i1 + i4, i1 + i3) + 1000000) % 10));
				}

	cout << ansi << endl << ansa << endl;
	return 0;
}