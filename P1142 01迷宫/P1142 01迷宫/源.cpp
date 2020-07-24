#include <iostream>

using namespace::std;

short dirsx[4] = { 1, 0, -1, 0 };
short dirsy[4] = { 0, 1, 0, -1 };
int main()
{
	char mat[1000][1000];
	int n = 0;
	cin >> n;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
			cin >> mat[i1][i2];
	long conm[1000][1000][8];
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < n; i2++)
		{
			long* here = conm[i1][i2];
			if (i2 == 0 || mat[i1][i2] == mat[i1][i2 - 1])
			{
				*(here + 4) = 0;
				*(here + 3) = 0;
			}
			else
				*(here + 4) = conm[i1][i2 - 1][4]
			if (i1 == 0)
			{
				*(here + 2) = 0;
				*(here + 3) = 0;
			}
			else if ( i2 != 0)
			{

	system("pause");
	return 0;
}