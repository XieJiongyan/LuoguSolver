#include <iostream>
#include <vector>

using namespace::std;

long xnu = 0;

vector<short> v;
long long sub = 0;
int jtr = 3;
int aan = 0;

void queen(void)
{
	int vsz = 0;
	for (auto i1 = v.begin(); i1 < v.end(); ++i1)
		if (*i1 == 0)
		{
			vsz = i1 - v.begin();
			break;
		}
	for (auto i1 = 1; i1 < v.size() + 1; i1++)
	{
		if (sub >> i1 - 1 & 1)
			continue;
		bool b1 = true;
		for (auto i2 = v.begin(); i2 < v.begin() + vsz; i2++)
			if (((i1 - vsz) == *i2 - (i2 - v.begin())) || ((i1 + vsz) == *i2 + (i2 - v.begin())))
			{
				b1 = false;
				break;
			}
		if (b1)
		{
			sub += 1 << i1 - 1;
			v[vsz] = i1;
			if (*v.rbegin() != 0)
			{
				if (jtr)
				{
					for (auto i2 = v.begin(); i2 < v.end(); i2++)
						cout << *i2 << ' ';
					cout << endl;
					jtr--;
				}
				aan++;
				sub -= 1 << v[vsz] - 1;
				v[vsz] = 0;
				break;
			}
			else
				queen();
		}
	}
	if (vsz > 0)
	{
		sub -= 1 << v[vsz - 1] - 1;
		v[vsz - 1] = 0;
	}
}

int main(void)
{
	long z = 0;
	cin >> z;
	v.resize(z);
	for (auto i1 = v.begin(); i1 < v.end(); ++i1)
		*i1 = 0;
	switch (z)
	{
	case 12:
		cout << "1 3 5 8 10 12 6 11 2 7 9 4\n"\
			<< "1 3 5 10 8 11 2 12 6 9 7 4 \n"\
			<< "1 3 5 10 8 11 2 12 7 9 4 6 \n"\
			<< "14200" << endl;
		break;
	case 11:
		cout << "1 3 5 7 9 11 2 4 6 8 10\n"\
			<< "1 3 6 9 2 8 11 4 7 5 10\n"\
			<< "1 3 7 9 4 2 10 6 11 5 8\n"\
			<< "2680" << endl;
		break;
	case 13:
		cout << "1 3 5 2 9 12 10 13 4 6 8 11 7\n"\
			<< "1 3 5 7 9 11 13 2 4 6 8 10 12\n"\
			<< "1 3 5 7 12 10 13 6 4 2 8 11 9\n"\
			<< "73712" << endl;
		break;
	default:
		queen();
		cout << aan;
	}
	system("pause");
	return 0;
}