#include <iostream>
#include <vector>
#include "Primernum.h"
using namespace::std;

void 
int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	vector<long long> v(n, 0);
	for (auto i = v.begin(); i < v.end(); ++i)
		cin >> *i;
	primernum.generate(1e8);
	vector<vector<long long>::iterator> vf(k, v.begin());
	for (auto i = vf.begin() + 1; i < vf.end(); ++i)
		*i = *(i - 1) + 1;
	vector<vector<long long>::iterator>::iterator iv = vf.end() - 1;
	while (true)
	{
		if (iv == vf.begin() && *iv != v.begin())
		{
			*iv++;
			iv++;
		}
		if (iv > vf.begin() && iv < vf.begin() - 1 && v.end() - *iv < vf.end() - iv)
		{
			*iv++;
			iv++;
		}

	}
	for (auto i = v.begin(); i < v.end(); ++i)
		cout << *i;
	cin >> n;
	return 0;
}

