#include "Verylongint.h"

Verylongint::Verylongint()
{
	num.push_back(0);
	positive = true;
}
Verylongint::~Verylongint()
{
}

Verylongint Verylongint::operator+(const Verylongint& a)
{
	Verylongint v;
	v.num.clear();
	bool b = true;
	bool b2 = true;
	int c = 0;
	for (auto i = 0; i < (num.size() > a.num.size() ? num.size() : a.num.size()); ++i)
	{
		int x = 0;
		if (i >= num.size())
			b = false;
		if (i >= a.num.size())
			b2 = false;
		if (b)
			x += num[i];
		if (b2)
			x += a.num[i];
		x += c;
		c = 0;
		if (x >= 10)
		{
			x -= 10;
			c = 1;
		}
		v.num.push_back(x);
	}
	return v;
}
void Verylongint::operator+=(const Verylongint& a)
{
	Verylongint v;
	v = *this + a;
	*this = v;
}
Verylongint Verylongint::operator*(const Verylongint& a)
{
	Verylongint v;
	v.num.clear();
	long now = 0;
	for (auto i = 0; i < num.size() + a.num.size() - 1; ++i)
	{
		for (auto i2 = num.begin(); i2 < num.end(); ++i2)
		{
			if (i2 - num.begin() > i)
				break;
			if (a.num.begin() + i - (i2 - num.begin()) >= a.num.end())
				continue;
			std::vector<int>::size_type x = i2 - num.begin();
			now += *i2 * *(a.num.begin() + i - (i2 - num.begin()));
		}
		v.num.push_back(now % 10);
		now /= 10;
	}
	while (now > 0)
	{
		v.num.push_back(now % 10);
		now /= 10;
	}
	return v;
}
Verylongint Verylongint::operator*(const long& a)
{
	Verylongint v1;
	v1 = a;
	return v1 * *this;
}
void Verylongint::operator*=(const long& a)
{
	Verylongint v;
	v = *this * a;
	*this = v;
}
void Verylongint::operator=(const long& l)
{
	num.clear();
	long l2 = l;
	if (l < 0)
	{
		positive = false;
		l2 = -l;
	}
	while (l2 != 0)
	{
		num.push_back(l2 % 10);
		l2 /= 10;
	}
}
ostream& operator<<(ostream& os, const Verylongint& a)
{
	for (auto i = a.num.rbegin(); i < a.num.rend(); ++i)
		os << *i;
	return os;
}