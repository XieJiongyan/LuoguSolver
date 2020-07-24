#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define SQU(a) ((a)*(a))
#define pi 3.1415926535

using namespace::std;

vector<double> vx;
vector<double> vy;
vector<double> vr;
long long ll = 0;
double xl = 0, xr = 0, yl = 0, yu = 0;
int n = 0;
double s = 0, sc = 0;
void dfs()
{
	for (auto i1 = 0; i1 < n; i1++)
		if (!((ll >> i1) & 1))
		{
			double r2 = min(vx[i1] - xl, xr - vx[i1]);
			r2 = min(r2, vy[i1] - yl);
			r2 = min(r2, yu - vy[i1]);
			for (auto i2 = 0; i2 < n; i2++)
				if ((ll >> i2) & 1)
					r2 = min(r2, sqrt(SQU(vx[i1] - vx[i2]) + SQU(vy[i1] - vy[i2])) - vr[i2] );
			r2 = max(r2, 0.0);
			vr[i1] = r2;
			ll += 1 << i1;
			sc += pi * r2 * r2;
			s = max(s, sc);
			dfs();
			vr[i1] = 0;
			ll -= 1 << i1;
			sc -= pi * r2 * r2;
		}
}

int main()
{
	n = 0;
	cin >> n;
	cin >> xl >> yl >> xr >> yu;
	if (xl > xr)
	{
		int x = xr;
		xr = xl;
		xl = x;
	}
	if (yl > yu)
	{
		int x = yu;
		yu = yl;
		yl = x;
	}
	vx.resize(n);
	vy.resize(n);
	vr.resize(n);
	for (auto i1 = 0; i1 < n; i1++)
		cin >> vx[i1] >> vy[i1];
	dfs();
	printf("%.0f", (xr - xl) * (yu - yl) - s);
	system("pause");
	return 0;
}