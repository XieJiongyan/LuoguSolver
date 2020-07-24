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
	long long mindivisor(long long);//获得第一形参的最小因数，不为1；若第一形参为1，返回1
	long countdiv(long long);//在目前的参数表下，获得第一形参的因数个数
	void generate(long long);//素数表增长至指定长度
private:
	Primernum& operator++();//素数表自增长一位
	Primernum& operator++(int);//素数表自增长一位
	vector<long long> all;
	bool express(long long);//在目前的素数表下，求得某数是不是合数
}primernum;

