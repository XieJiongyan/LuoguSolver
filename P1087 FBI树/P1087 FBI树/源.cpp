#include <iostream>
#include <string>

using namespace::std;
int n = 0;
string fbi;
string s;
void lrd(int ih)
{
	if (!(ih & (1 << n)))
	{
		lrd(ih * 2);
		lrd(ih * 2 + 1);
	}
	cout << fbi[ih];
	return;
}

void bui(int ih, char type)
{
	if (type == 'F')
	{
		int ind = 1;
		for (ind = 1; ; ind <<= 1)
			if (ih < (ind << 1))
				break;
		int ifc = (ih - ind) *((1 << n) / ind) + 1;
		type = s[ifc];
		for (ifc += 1; ifc <= (ih - ind + 1) * ((1 << n) / ind); ifc++)
			if (s[ifc] != type)
			{
				type = 'F';
				break;
			}
	}
	fbi[ih] = type;
	if (ih < (1 << n))
	{
		bui(ih * 2, type);
		bui(ih * 2 + 1, type);
	}
	return;
}

int main()
{
	cin >> n;
	cin >> s;
	fbi.resize((1 << n + 1) + 1);
	s = 'J' + s;
	for (auto i1 = s.begin(); i1 < s.end(); i1++)
		switch (*i1)
		{
		case '0':
			*i1 = 'B';
			break;
		case '1':
			*i1 = 'I';
		}
	bui(1, 'F');
	lrd(1);
	system("pause");
	return 0;
}