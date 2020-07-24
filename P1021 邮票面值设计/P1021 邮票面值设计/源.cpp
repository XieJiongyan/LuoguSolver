#include <iostream>
#include <algorithm>
#include <vector>

#define DPSIZE 10000

using namespace::std;

int dp[DPSIZE] = { 0 };
vector<int> vus;
vector<int> vusc;

int n = 0, k = 0;
int man = 0;

int fdp()
{
	int liv = *vusc.rbegin() * n;
	for (auto i1 = 1; i1 < liv; i1++)
		dp[i1] = 0x77ffffff;
	for (auto i1 : vusc)
		for (auto i2 = i1; i2 <= liv; i2++)
			dp[i2] = min(dp[i2], dp[i2 - i1] + 1);
	for (auto i1 = 0; i1 <= liv; i1++)
		if (dp[i1] > n)
			return i1 - 1;
	return liv;
}
void dfs(int sta, int ran)// ran means the maxinum of what nums in vusc can make ;sta means have already manage the num of sta
{
	if (sta >= k)
	{
		if (man < ran)
		{
			man = ran;
			vus = vusc;
		}
	}
	else
	{
		for (auto i1 = *vusc.rbegin() + 1; i1 <= ran + 1; i1++)
		{
			vusc.push_back(i1);
			dfs(sta + 1, fdp());
			vusc.pop_back();
		}
	}
}
int main()
{
	cin >> n >> k;
	vusc.push_back(1);
	dfs(1, n);
	for (auto i1 : vus)
		cout << i1 << ' ';
	cout << endl << "MAX=" << man << endl;
	return 0;
}