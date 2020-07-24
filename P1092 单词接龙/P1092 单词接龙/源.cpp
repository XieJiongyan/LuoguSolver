#include <iostream>
#include <vector>
#include <string>

using namespace::std;

vector<string> vs;
vector<int> vb;

long ans = 0;
long anso = 0;
void dfs(string s)
{
	if (anso < ans)
		anso = ans;
	for (auto i1 = s.rbegin(); i1 < s.rend() - 1; i1++)
	{
		string sw;
		for (auto i2 = i1; ; --i2)
		{
			sw.push_back(*i2);
			if (i2 == s.rbegin())
				break;
		}
		auto i2 = vs.begin();
		for (; i2 < vs.end(); ++i2)
		{
			if (!*(vb.begin() + (i2 - vs.begin())))
				continue;
			bool b = true;
			auto i3 = 0;
			while (true)
			{
				if (i3 == sw.size())
					break;
				if (i3 == i2->size() - 1 || sw[i3] != *(i2->begin() + i3))
				{
					b = false;
					break;
				}
				i3++;
			}
			if (!b)
				continue;
			vb[i2 - vs.begin()]--;
			ans += i2->size() - (i1 - s.rbegin() + 1);
			dfs(*i2);
 			vb[i2 - vs.begin()]++;
			ans -= i2->size() - (i1 - s.rbegin() + 1);
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	vs.resize(n);
	vb.resize(n);
	for (auto i1 = 0; i1 < n; i1++)
	{
		cin >> vs[i1];
		vb[i1] = 2;
	}
	char c = '>';
	cin >> c;
	for (auto i1 = vs.begin(); i1 < vs.end(); ++i1)
		if (*i1->begin() == c)
		{
			vb[i1 - vs.begin()]--;
			ans += i1->size();
			dfs(*i1);
			vb[i1 - vs.begin()]++;
			ans -= i1->size();
		}
	cout << anso;
	system("pause");
	return 0;
}

