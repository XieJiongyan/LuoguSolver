#include <iostream>
#include <string>

using namespace::std;

int main()
{
	int p1 = 0, p2 = 0, p3 = 0;
	string s;
	cin >> p1 >> p2 >> p3;
	cin >> s;
	for (auto i = s.begin(); i < s.end(); ++i)
	{
		if ((*i == '-' && i > s.begin() && i < s.end() - 1) && *(i - 1) < *(i + 1) && \
			((*(i - 1) >= 'a' && *(i + 1) >= 'a' && *(i - 1) <= 'z' && *(i + 1) <= 'z') || \
			(*(i - 1) <= '9' && *(i + 1) <= '9' && *(i + 1) >= '0' && *(i - 1) >= '0')))
		{
			char cf, ce;
			int ia = 0;
			if (p3 == 1)
			{
				cf = *(i - 1);
				ce = *(i + 1);
				ia = 1;
			}
			else
			{
				cf = *(i + 1);
				ce = *(i - 1);
				ia = -1;
			}
			for (char i2 = cf + ia; (p3 == 1 ? i2 < ce : i2 > ce); i2 += ia)
			{
				for (auto i3 = 0; i3 < p2; i3++)
				{
					if (p1 == 1 && *(i - 1) >= 'a' && *(i - 1) <= 'z')
						cout << i2;
					else if (p1 == 2 && *(i - 1) >= 'a' && *(i - 1) <= 'z')
						cout << static_cast<char>(i2 - 'a' + 'A');
					else if (p1 <= 2 && *(i - 1) >= '0' && *(i - 1) <= '9')
						cout << i2;
					else if (p1 == 3)
						cout << '*';
				}
			}
		}
		else
			cout << *i;
	}
	system("pause");
	return 0;
}