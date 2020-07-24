#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace::std;

vector<int> vst;
deque<bool> vb1;
vector<int> vne;

void dfs(int por, int now)
{
	if (now == por)
	{
		auto it1 = find(vb1.rbegin(), vb1.rend(), true);
		if (it1 == vb1.rend())
		{
			cout << por << endl;
			exit(0);
		}
		//cout << vb1.rend() - it1 << " * " << endl;
		*it1 = false;
		dfs(por, *(vst.rbegin() + (it1 - vb1.rbegin())));
		*it1 = true;
		return;
	}
	auto it2 = vb1.rbegin();
	int il = 100;
	for (auto i1 = lower_bound(vst.rbegin(), vst.rend(), por - now, greater<int>()); ; i1 = vst.begin() + vne[(vst.rend())
	{
		it2 = vb1.rbegin() + (i1 - vst.rbegin());
		if (*i1 != il && *it2)
		{
			//cout << vb1.rend() - it2 << " # " << endl;
			il = *i1;
			*it2 = false;
			dfs(por, now + *i1);
			//cout << " & " << endl;
			*it2 = true;
			if (now + *i1 == por)
				return;
		}
	}
}
int main()
{
	int n = 0;
	cin >> n;
	int inn = 0;
	for (auto i1 = 0; i1 < n; i1++)
	{
		cin >> inn;
		if (inn <= 50)
			vst.push_back(inn);
	}
	vb1.resize(vst.size());
	int sum = 0;
	sort(vst.begin(), vst.end());
	vne.resize(vst.size());
	*vne.begin() = -1;
	for (auto i1 = vne.begin() + 1, ii1 = vst.begin() + 1; i1 < vne.end(); i1++, ii1++)
		if (*ii1 == *(ii1 - 1))
			*i1 = *(i1 - 1);
		else
			*i1 = i1 - vne.begin() - 1;
	for (auto& i1 : vst)
		sum += i1;
	for (auto i1 = *vst.rbegin(); i1 <= sum; i1++)
		if (sum % i1 == 0)
		{
			for (auto& i1 : vb1)
				i1 = true;
			dfs(i1, i1);
		}
	return 0;
}
