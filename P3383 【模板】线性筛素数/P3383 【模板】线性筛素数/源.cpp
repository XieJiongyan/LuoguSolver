#include <iostream>
#include <vector>

using namespace::std;

vector<long> prn;
bool nop[10000001] = { false };//false means is prime

void f(long n)
{
	nop[1] = true;
	for (auto i1 = 2; i1 < n; i1++)
	{
		if (!nop[i1])
			prn.push_back(i1);
		for (auto i2 = prn.begin(); i2 < prn.end() && i1 * *i2 <= 10000001; i2++)
		{
			nop[i1 * *i2] = true;
			if (i1 % *i2 == 0)
				break;
		}
	}
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<long> v(m);
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
		cin >> *i1;
	f(n);
	for (auto i1 = v.begin(); i1 < v.end(); i1++)
		if (nop[*i1])
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	system("pause");
	return 0;
}