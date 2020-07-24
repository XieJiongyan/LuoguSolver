#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

struct Cl
{
	long num;
	long score;
	bool operator<(Cl);
};

inline bool Cl::operator<(Cl c)
{
	if (score < c.score)
		return true;
	else if (score == c.score)
		return num > c.num;
	else
		return false;
}

int main()
{
	long n = 0, m = 0;
	cin >> n >> m;
	vector<Cl> v(n);
	for (auto i1 = 0; i1 < n; ++i1)
		cin >> v[i1].num >> v[i1].score;
	sort(v.rbegin(), v.rend());
	long pc = v[(m * 3 / 2)- 1].score;
	cout << pc << ' ';
	for (auto i1 = v.begin() + (m * 3 / 2); i1 < v.end(); ++i1)
		if (i1->score < pc)
		{
			cout << i1 - v.begin() << endl;
			break;
		}
	for (auto i1 = v.begin(); i1->score >= pc; ++i1)
		cout << i1->num << ' ' << i1->score << endl;
	system("pause");
	return 0;
}