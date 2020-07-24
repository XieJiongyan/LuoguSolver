#include <iostream>

#define MIT_SIZE 500005
using namespace::std;

int mit[MIT_SIZE] = { 0 };

void ins_mit(int poi, int val)
{
	for (; poi < MIT_SIZE; poi += poi & -poi)
		mit[poi] += val;
}
int srh_mit(int l, int r)
{
	int rev = 0;
	for (r--; r > 0; r -= r & -r)
		rev += mit[r];
	for (l--; l > 0; l -= l & -l)
		rev -= mit[l];
	return rev;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	int in1 = 0;
	for (auto i1 = 1; i1 < n + 1; i1++)
	{
		cin >> in1;
		ins_mit(i1, in1);
	}
	int in2, in3;
	for (auto i1 = 0; i1 < m; i1++)
	{
		cin >> in1 >> in2 >> in3;
		switch (in1)
		{
		case 1:
			ins_mit(in2, in3);
			break;
		case 2:
			cout << srh_mit(in2, in3 + 1) << endl;
			break;
		}
	}
	return 0;
}