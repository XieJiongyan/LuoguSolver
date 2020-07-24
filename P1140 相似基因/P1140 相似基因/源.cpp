#include <iostream>
#include <algorithm>

using namespace::std;

long rld[5][5] = {
	{ 5, -1, -2, -1, -3},
	{ -1, 5, -3, -2, -4},
	{ -2, -3, 5, -2, -2},
	{ -1, -2, -2, 5, -1},
	{ -3, -4, -2, -1, 0} };

int main()
{
	int sab[2] = { 0 };
	short jab[100][2] = { 0 };
	for (auto i1 = 0; i1 < 2; i1++)
	{
		cin >> sab[i1];
		char coc = 0;
		for (auto i2 = 0; i2 < sab[i1]; i2++)
		{
			cin >> coc;
			switch (coc)
			{
			case 'A':
				jab[i2][i1] = 0;
				break;
			case 'C':
				jab[i2][i1] = 1;
				break;
			case 'G':
				jab[i2][i1] = 2;
				break;
			case 'T':
				jab[i2][i1] = 3;
				break;
			}
		}
	}
	int dp[101][101] = { 0 };
	for (auto i1 = 1; i1 <= sab[0]; i1++)
		dp[i1][0] = dp[i1 - 1][0] + rld[jab[i1 - 1][0]][4];
	for (auto i1 = 1; i1 <= sab[1]; ++i1)
		dp[0][i1] = dp[0][i1 - 1] + rld[jab[i1 - 1][1]][4];
	for (auto i1 = 1; i1 <= sab[0]; i1++)
		for (auto i2 = 1; i2 <= sab[1]; i2++)
		{
			long thv = max(dp[i1 - 1][i2] + rld[jab[i1 - 1][0]][4], dp[i1][i2 - 1] + rld[jab[i2 - 1][1]][4]);
			thv = max(thv, dp[i1 - 1][i2 - 1] + rld[jab[i1 - 1][0]][jab[i2 - 1][1]]);
			dp[i1][i2] = thv;
		}
	cout << dp[sab[0]][sab[1]] << endl;
	system("pause");
	return 0;
}