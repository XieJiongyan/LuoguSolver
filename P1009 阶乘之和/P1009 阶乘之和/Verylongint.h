#pragma once

#include <vector>
#include <iostream>

using std::ostream;

class Verylongint
{
public:
	Verylongint();
	~Verylongint();
	Verylongint operator+(const Verylongint&);
	void operator+=(const Verylongint&);
//	Verylongint operator-(const Verylongint&);
	Verylongint operator*(const Verylongint&);
	Verylongint operator*(const long&);
	void operator*=(const long&);
//	Verylongint operator/(const Verylongint&);
	friend ostream& operator<<(ostream&, const Verylongint&);
	void operator=(const long&);
private:
	std::vector<int> num;
	bool positive;
};
/* it can only deal with positive int now*/
