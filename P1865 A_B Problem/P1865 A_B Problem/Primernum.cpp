#include "Primernum.h"

Primernum primernum;

Primernum::~Primernum()
{
}
long long Primernum::mindivisor(long long num)
{
	generate(static_cast<long long>(sqrt(static_cast<double>(num))));
	for (vector<long long>::iterator i = all.begin(); i < all.end(); i++)
		if (num % *i == 0)
			return *i;
	return num;
}
Primernum::Primernum()
{
	all.push_back(2);
}
Primernum::Primernum(const Primernum& pri)
{
	all = pri.all;
}
Primernum& Primernum::operator++()
{
	long long next = all.back() + 1;
	while (true)
	{
		if (!express(next++))
		{
			all.push_back(next);
			return *this;
		}
	}
}
Primernum Primernum::operator++(int)
{
	Primernum ret(*this);
	long long next = all.back() + 1;
	while (true)
	{
		if (!express(next++))
		{
			all.push_back(next);
			return ret;
		}
	}
}
void Primernum::generate(long long until)
{
	all.clear();
	vector<bool> v(until, true);
	for (auto i = v.begin() + 1; i < v.end(); ++i)
	{
		if (*i)
		{
			all.push_back(i - v.begin() + 1);
			for (auto i2 = i; i2 < v.end(); i2 += *all.rbegin())
				*i2 = false;
		}
	}
}
bool Primernum::express(long long n)
{
	long long m = n;
	vector<long long>::iterator i = all.begin();
	while (m > 1 && i < all.end())
	{
		if (m % *i == 0)
			m /= *i;
		else
			i++;
	}
	if (m == 1)
		return true;
	else
		return false;
}
long Primernum::countdiv(long long n)
{
	vector<long> v(all.size(), 0);
	for (auto i = 0; i < all.size(); ++i)
	{
		while (n % all[i] == 0)
		{
			n /= all[i];
			++v[i];
		}
		if (n == 1)
			break;
	}
	long ans = 1;
	for (auto i = v.begin(); i < v.end(); ++i)
		ans *= *i + 1;
	return ans;
}
