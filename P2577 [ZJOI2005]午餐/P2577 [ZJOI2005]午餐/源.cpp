#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

#define BIT_SIZE 200
#define ARRAY_SIZE 40500

using namespace::std;

int bit[BIT_SIZE] = { 0 };

void ins_bit(int poi, int num)
{
	for (; poi < BIT_SIZE; poi += poi & -poi)
		bit[poi] += num;
}

int srh_bit(int le, int ri)
{
	le--, ri--;
	int ans = 0;
	for (; ri > 0; ri -= ri & -ri)
		ans += bit[ri];
	for (; le > 0; le -= le & -le)
		ans -= bit[le];
	return ans;
}

array<int, ARRAY_SIZE> dp;

struct St
{
	int buy;
	int eat;
	bool operator<(St);
};
inline bool St::operator<(St st)
{
	return eat < st.eat;
}

int main()
{
	for (auto& i1 : dp)
		i1 = 0x7000ffff;
	int n = 0;
	cin >> n;
	vector<St> v(n);
	for (auto& i1 : v)
		cin >> i1.buy >> i1.eat;
	sort(v.begin(), v.end());
	for(auto i1 : v)
		for (auto i2 = n * 200; i2 > i1.buy - 1; i2++)
		{
			dp[i2] = min(dp[i2], max(dp[i2 - i1.buy], i2 + i1.eat));
			dp[i2] = min(dp[i2], max(dp