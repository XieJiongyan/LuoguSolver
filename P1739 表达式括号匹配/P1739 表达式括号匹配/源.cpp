#include <iostream>
#include <string>

using namespace::std;

int main()
{
	string s;
	cin >> s;
	int x = 0;
	for (auto i1 = s.begin(); i1 < s.end(); i1++)
	{
		if (*i1 == '(')
			x++;
		else if (*i1 == ')')
			x--;
		if (x < 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << (x == 0 ? "YES" : "NO") << endl;
	system("pause");
	return 0;
}