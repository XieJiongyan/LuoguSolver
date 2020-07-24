#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string num[26] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",\
"thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third" };
using namespace::std;

int main()
{
	string s;
	string ans;
	vector<long> v;
	while (cin >> s)
	{
		if (s == ".")
			break;
		for (int i = 0; i < 20; ++i)
			if (s == num[i])
			{
				v.push_back(((i + 1) * (i + 1)) % 100);
				break;
			}
		if (s == num[20] || s == num[22] || s == num[23])
			v.push_back(1);
		else if (s == num[21] || s == num[24])
			v.push_back(4);
		else if (s == num[25])
			v.push_back(9);
	}
	bool b1 = true;
	sort(v.begin(), v.end());
	if ((v.size() >= 1 && *(v.end() - 1) == 0) || v.empty())
		cout << '0';
	for (auto i = v.begin(); i < v.end(); ++i)
	{
		if (!b1 || *i / 10 != 0)
			cout << *i / 10;
		if (*i / 10 != 0)
			b1 = false;
		if (!b1 || *i % 10 != 0)
			cout << *i % 10;
		if (!b1 || *i % 10)
			b1 = false;
	}
	system("pause");
	return 0;
}