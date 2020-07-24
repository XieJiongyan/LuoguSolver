#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	long n = 0;
	cin >> n;
	vector<long> x1(n);
	vector<long> x2(n);
	vector<long> y1(n);
	vector<long> y2(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x1[i];
		cin >> y1[i];
		cin >> x2[i];
		cin >> y2[i];
	}
	long x = 0, y = 0;
	cin >> x >> y;
	long ans = -1;
	for(int i = n -1; i >= 0; --i)
		if (x1[i] <= x && x <= x1[i] + x2[i] && y1[i] <= y && y <= y1[i] + y2[i])
		{
			ans = i + 1;
			break;
		}
	cout << ans;
	system("pause");
	return 0;
}