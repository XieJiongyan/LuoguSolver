#include <iostream>
#include <string>
#include <vector>

using namespace::std;

int main()
{
	string s, s2;
	while (cin >> s2)
		s += s2;
	int w = 0, l = 0;
	int w2 = 0, l2 = 0;
	vector<long> v1, v2;
	for (auto i = s.begin(); i < s.end(); ++i)
	{
		switch (*i)
		{
		case 'W':
			w++;
			w2++;
			break;
		case 'L':
			l++;
			l2++;
			break;
		}
		if ((w >= 11 && w - l >= 2) || (l >= 11 && l - w >= 2)|| (*i == 'E'  /*&& w + l !=0*/))
		{
			cout << w << ":" << l << endl;
			w = 0;
			l = 0;
		}
		if ((w2 >= 21 && w2 - l2 >= 2) || (l2 >= 21 && l2 - w2 >= 2) || (*i == 'E' /*&& w2 + l2 != 0*/))
		{
			v1.push_back(w2);
			v2.push_back(l2);
			w2 = 0;
			l2 = 0;
		}
		if (*i == 'E')
			break;
	}
	cout << endl;
	for (auto i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << ":" << v2[i] << endl;
	}
	system("pause");
	return 0;
}