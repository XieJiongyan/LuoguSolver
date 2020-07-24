#include <iostream>
#include <vector>
#include <string>

using namespace::std;

int main()
{
	vector<char> v(26, '?');
	string s, sd, sl;
	cin >> s >> sd >> sl;
	if (s.size() != sd.size())
	{
		cout << "Failed" << endl;
		return 0;
	}
	for (auto i = 0; i < s.size(); i++)
	{
		if (v[s[i] - 'A'] == '?')
			v[s[i] - 'A'] = sd[i];
		else if (v[s[i] - 'A'] != sd[i])
		{
			cout << "Failed" << endl;
			system("pause");
			return 0;
		}
	}
	for(auto i = v.begin(); i< v.end(); ++i)
		if (*i == '?')
		{
			cout << "Failed" << endl;
			return 0;
		}
	vector<bool> vc(26, true);
	for(auto i = v.begin(); i < v.end(); ++i)
		vc[*i - 'A'] = false;
	for(auto i = vc.begin(); i < vc.end(); ++i)
		if (*i)
		{
			cout << "Failed" << endl;
			return 0;
		}
	for (auto i = 0; i < sl.size(); ++i)
		cout << v[sl[i] - 'A'];
	system("pause");
	return 0;
}