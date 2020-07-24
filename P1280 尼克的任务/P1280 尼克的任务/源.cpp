#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

struct St
{
	long ft;
	long lt;
	bool operator<(St);
};

bool St::operator<(St st)
{
	return ft < st.ft;
}

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	vector<long> vt(n + 1, 0);

	vector<St> vst(k);
	for (auto i1 = vst.begin(); i1 < vst.end(); i1++)
		cin >> i1->ft >> i1->lt;
	for (auto i1 = vst.begin(); i1 < vst.end(); i1++)
		i1->ft--;
	sort(vst.rbegin(), vst.rend());
	auto pvst = vst.begin();
	for (auto i1 = n - 1; i1 >= 0; i1--)
		if (pvst == vst.end() ||pvst->ft != i1)
			vt[i1] = vt[i1 + 1] + 1;
		else for (; pvst < vst.end() && pvst->ft == i1; pvst++)
			vt[i1] = max(vt[i1], vt[i1 + pvst->lt]);
	cout << vt[0] << endl;
	system("pause");
	return 0;
}
