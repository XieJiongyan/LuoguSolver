#include <iostream>
#include <string>

using namespace::std;

void dlr(string sl, string sd)
{
	if (!sl.empty())
		cout << *sl.rbegin();
	if (sl.size() <= 1)
		return;
	auto i1 = sd.begin();
	for (; i1 < sd.end(); i1++)
		if (*i1 == *sl.rbegin())
			break;
	string sdn;
	string sln;
	for (auto ii1 = sd.begin(); ii1 < i1; ii1++)
	{
		sdn.push_back(*ii1);
		sln.push_back(*(sl.begin() + (ii1 - sd.begin())));
	}
	dlr(sln, sdn);
	sdn.clear();
	sln.clear();
	for (auto ii1 = i1 + 1; ii1 < sd.end(); ii1++)
	{
		sdn.push_back(*ii1);
		sln.push_back(*(sl.begin() + (ii1 - sd.begin()) - 1));
	}
	dlr(sln, sdn);
}

int main()
{
	string ldr, lrd;
	cin >> ldr >> lrd;
	dlr(lrd, ldr);
	system("pause");
	return 0;
}