#pragma once

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
