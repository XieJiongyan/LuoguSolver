#pragma once
#include <vector>
#include <cmath>

using std::vector;

class Primernum
{
public:
	Primernum();
	~Primernum();
	Primernum(const Primernum&);
	long long mindivisor(long long);//获得第一参数的最小公因数，不为1；若第一参数为1，返回1
	void generate(long long);//素数表增长至指定长度
private:
	Primernum& operator++();//素数表自增长一位
	Primernum& operator++(int);//素数表自增长一位
	vector<long long> all;
	bool express(long long);
}primernum;
