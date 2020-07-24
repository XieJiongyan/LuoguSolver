#include <iostream>
#include <vector>

using namespace::std;

int mty[5][5] =
{
	{0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0}
};

int main()
{
	int n, na, nb;
	cin >> n >> na >> nb;
	long sco[2] = { 0 };
	vector<long> va(na), vb(nb);
	for (auto i1 = va.begin(); i1 < va.end(); i1++)
		cin >> *i1;
	for (auto i2 = vb.begin(); i2 < vb.end(); i2++)
		cin >> *i2;
	for (auto i1 = 0; i1 < n; i1++)
	{
		sco[0] += mty[va[i1 % na]][vb[i1 % nb]];
		sco[1] += mty[vb[i1 % nb]][va[i1 % na]];
	}
	cout << sco[0] << ' ' << sco[1] << endl;
	system("pause");
	return 0;
}