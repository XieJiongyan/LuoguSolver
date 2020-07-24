#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace::std;

int main()
{
	string a, b;
	cin >> a >> b;
	vector<string> bfc;
	vector<string> afc;
	string cont, cont2;
	while (cin >> cont >> cont2)
	{
		bfc.push_back(cont);
		afc.push_back(cont2);
	}
	queue<string> qs;
	queue<int> qi;
	set<string> ses;
	qs.push(a);
	qi.push(0);
	while (true)
	{
		string& sd = qs.front();
		for (auto i2 = sd.begin(); i2 < sd.end(); i2++)
		{
			for (auto i1 = 0; i1 < bfc.size(); i1++)
			{
				if (sd.size() - (i2 - sd.begin()) < bfc[i1].size())
					continue;
				bool b1 = true;
				for (auto i3 = i2; i3 < i2 + bfc[i1].size(); i3++)
					if (*i3 != bfc[i1][i3 - i2])
					{
						b1 = false;
						break;
					}
				if (b1)
				{
					string sa;
					for (auto i3 = sd.begin(); i3 < i2; i3++)
						sa.push_back(*i3);
					sa += afc[i1];
					if (i2 - sd.begin() + bfc[i1].size() < sd.size())
						for (auto i3 = i2 + bfc[i1].size(); i3 < sd.end(); i3++)
							sa.push_back(*i3);
					if (sa == b)
					{
						cout << qi.front() + 1 << endl;
						system("pause");
						return 0;
					}
					if (ses.find(sa) == ses.end())
					{
						ses.insert(sa);
						qs.push(sa);
						qi.push(qi.front() + 1);
					}
				}
			}
		}
		qs.pop();
		if (qs.empty())
		{
			cout << "NO ANSWER!" << endl;
			return 0;
		}
		qi.pop();
	}
	return 0;
}