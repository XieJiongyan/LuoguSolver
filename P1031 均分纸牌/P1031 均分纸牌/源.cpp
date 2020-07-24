#include <iostream>
#include <vector>

int main()
{
	int n = 0;
	int rev = 0;
	std::vector<long> v;
	std::cin >> n;
	for (auto i = 0; i < n; ++i)
	{
		long x = 0;
		std::cin >> x;
		v.push_back(x);
	}
	long ave = 0;
	long all = 0;
	for (auto i = v.begin(); i < v.end(); ++i)
		all += *i;
	ave = all / n;
	std::vector<long>::iterator a = v.begin();
	for (auto i = v.begin(); i < v.end(); ++i)
	{
		if (i > a)
		{
			long x = 0;
			for (auto i2 = a; i2 < i; ++i2)
				x += *i2;
			x += *i;
			if (x >= ave * (i - a + 1))
			{
				rev += (i - a);
				*i = x - ave * (i - a);
				a = i;
			}
		}
		if (i == a && *i > ave)
		{
			*(i + 1) += *i - ave;
			rev++;
		}
		if (i == a && *i >= ave && a != v.end() - 1)
			a++;
	}
	std::cout << rev;
	std::cin >> n;
	return 0;
}