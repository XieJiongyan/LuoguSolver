#include "Primernum.h"



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
Primernum& Primernum::operator++(int)
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
void Primernum::generate(long long until)
{
	long long next = all.back();
	while (++next <= until)
		if (!express(next))
			all.push_back(next);

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
