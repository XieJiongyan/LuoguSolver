#include <iostream>
#include <vector>
#include <iostream>
#include <string>

using std::ostream;
using std::istream;

class Verylongint
{
public:
	Verylongint();
	Verylongint(const long&);
	Verylongint(const Verylongint&);
	~Verylongint();
	Verylongint operator+(const Verylongint&);
	void operator+=(const Verylongint&);
	friend Verylongint operator-(Verylongint, Verylongint);
	friend Verylongint operator-(const Verylongint&);
	Verylongint operator*(const Verylongint&);
	Verylongint operator*(const long&);
	void operator*=(const long&);
	friend ostream& operator<<(ostream&, const Verylongint&);
	friend istream& operator>>(istream&, Verylongint&);
	void operator=(const long&);
	bool operator==(const Verylongint&);
	bool operator<(const Verylongint&);
	bool operator>(const Verylongint&);
	bool operator<=(const Verylongint&);
	bool operator>=(const Verylongint&);
private:
	std::vector<int> num;
	bool positive;
};
/* it can only deal with positive int now*/
Verylongint::Verylongint()
{
	num.push_back(0);
	positive = true;
}
Verylongint::Verylongint(const long& l)
{
	num.clear();
	if (l == 0)
	{
		positive = true;
		num.push_back(0);
		return;
	}
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
Verylongint::Verylongint(const Verylongint& v)
{
	num = v.num;
	positive = v.positive;
}
Verylongint::~Verylongint()
{
}

Verylongint Verylongint::operator+(const Verylongint& a)
{
	Verylongint v;
	if (this->positive && a.positive)
	{
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
		if (c > 0)
			v.num.push_back(c);
	}
	else if (!this->positive && a.positive)
		v = a - -*this;
	else if (this->positive && !a.positive)
		v = *this - -a;
	else
		v = -(-v + -*this);
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
	if (l == 0)
	{
		num.push_back(0);
		return;
	}
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
	if (!a.positive)
		os << '-';
	for (auto i = a.num.rbegin(); i < a.num.rend(); ++i)
		os << *i;
	return os;
}
istream& operator>>(istream& is, Verylongint& a)
{
	std::string s;
	is >> s;
	a.num.clear();
	if (*s.begin() == '-')
	{
		s.erase(s.begin());
		a.positive = false;
	}
	else
		a.positive = true;
	for (auto i = s.rbegin(); i < s.rend(); ++i)
		a.num.push_back(*i - '0');
	return is;
}
bool Verylongint::operator<(const Verylongint& v)
{
	if (*this == v)
		return false;
	if (positive == true && v.positive == false)
		return false;
	if (positive == false && v.positive == true)
		return true;
	bool ans = true;
	if (num.size() > v.num.size())
		ans = false;
	else if (num.size() == v.num.size())
	{
		auto ic = v.num.rbegin();
		for (auto i = num.rbegin(); i < num.rend(); ++i, ++ic)
			if (*i > *ic)
			{
				ans = false;
				break;
			}
			else if (*i < *ic)
			{
				ans = true;
				break;
			}
	}
	if (positive == false)
		ans = !ans;
	return ans;
}
bool Verylongint::operator==(const Verylongint& v)
{
	if (positive == v.positive && num == v.num)
		return true;
	else
		return false;
}
bool Verylongint::operator>(const Verylongint& v)
{
	return (!(*this < v) && !(*this == v));
}
bool Verylongint::operator<=(const Verylongint& v)
{
	return (*this < v || *this == v);
}
bool Verylongint::operator>=(const Verylongint& v)
{
	return !(*this < v);
}
Verylongint operator-(const Verylongint& v)
{
	Verylongint vr(v);
	vr.positive = !vr.positive;
	return vr;
}
Verylongint operator-(Verylongint x, Verylongint v)
{
	Verylongint va(0);
	if (x.positive && v.positive)
	{
		if (x > v)
		{
			va.num.clear();
			auto ic = v.num.begin();
			int b = 0;
			for (auto i1 = x.num.begin(); i1 < x.num.end(); ++i1)
				if (*i1 - b < (ic == v.num.end() ? 0 : *ic))
				{
					va.num.push_back(*i1 - b + 10 - (ic == v.num.end() ? 0 : *ic++));
					b = 1;
				}
				else
				{
					va.num.push_back(*i1 - b - (ic == v.num.end() ? 0 : *ic++));
					b = 0;
				}
			va.positive = true;
			while (*va.num.rbegin() == 0)
				va.num.pop_back();
			return va;
		}
		else if (x == v)
			return va;
		else
		{
			va = v - x;
			va.positive = false;
			return va;
		}
	}
	else if (x.positive && !v.positive)
		va = x + (-v);
	else if (!x.positive && v.positive)
		va = -(-x + v);
	else if (x.positive && !v.positive)
		va = -x - -v;
	return va;
}

using namespace::std;

int main()
{
	Verylongint a = 0, b = 0;
	cin >> a >> b;
	cout << a - b << endl;
	system("pause");
	return 0;
}