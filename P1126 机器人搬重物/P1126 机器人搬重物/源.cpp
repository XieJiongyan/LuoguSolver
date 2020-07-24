#include <iostream>
#include <queue>

using namespace::std;

int diry[4] = { 1, 0, -1, 0 };
int dirx[4] = { 0, -1, 0, 1 };

int main()
{
	bool mat[50][50] = { false };
	int m = 0, n = 0;
	cin >> n >> m;
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			cin >> mat[i1][i2];
	long qest[50][50][4];
	for (auto i1 = 0; i1 < n; i1++)
		for (auto i2 = 0; i2 < m; i2++)
			for (auto i3 = 0; i3 < 4; i3++)
				qest[i1][i2][i3] = -1;
	queue<long> que;
	int xn = 0, yn = 0, xe = 0, ye = 0;
	char dir = ' ';
	cin >> xn >> yn >> xe >> ye >> dir;
	long ln = xn * 10000 + yn * 100;
	switch (dir)
	{
	case 'E':
		ln += 0;
		break;
	case 'N':
		ln += 1;
		break;
	case 'W':
		ln += 2;
		break;
	case 'S':
		ln += 3;
		break;
	}
	que.push(ln);
	qest[ln / 10000][(ln / 100) % 100][ln % 100] = 0;
	while (!que.empty())
	{
		long xt = que.front() / 10000;
		long yt = (que.front() / 100) % 100;
		long dirt = que.front() % 4;
		//for (auto i1 = 0; i1 < n; i1++)
		//{
		//	for (auto i2 = 0; i2 < m; i2++)
		//		if ((xt == i1 && yt == i2) || (xt == i1 + 1 && yt == i2) || (xt == i1 && yt == i2 + 1)|| (xt == i1 + 1 && yt == i2 + 1))
		//			cout << "X ";
		//		else
		//			cout << mat[i1][i2] << ' ';
		//	cout << endl;
		//}
		//cout << dirt << ' ' << qest[xt][yt][dirt] << endl;
		//system("pause");
		if (xt == xe && yt == ye)
		{
			cout << qest[xt][yt][dirt];
			system("pause");
			return 0;
		}
		int st = 1;
		int xne = xt + dirx[dirt] * st;
		int yne = yt + diry[dirt] * st;
		if (xne > 0 && xne < n && yne > 0 && yne < m && !mat[xne][yne] && !mat[xne - 1][yne] && !mat[xne][yne - 1] && !mat[xne - 1][yne - 1])
		{
			if (qest[xne][yne][dirt] == -1)
			{
				qest[xne][yne][dirt] = qest[xt][yt][dirt] + 1;
				que.push((xne) * 10000 + yne * 100 + dirt);
			}
			st = 2;
			xne = xt + dirx[dirt] * st;
			yne = yt + diry[dirt] * st;
			if (xne > 0 && xne < n && yne > 0 && yne < m && !mat[xne][yne] && !mat[xne - 1][yne] && !mat[xne][yne - 1] && !mat[xne - 1][yne - 1])
			{
				if (qest[xne][yne][dirt] == -1)
				{
					qest[xne][yne][dirt] = qest[xt][yt][dirt] + 1;
					que.push((xne) * 10000 + yne * 100 + dirt);
				}
				st = 3;
				xne = xt + dirx[dirt] * st;
				yne = yt + diry[dirt] * st;
				if (xne > 0 && xne < n && yne > 0 && yne < m && !mat[xne][yne] && !mat[xne - 1][yne] && !mat[xne][yne - 1] && !mat[xne - 1][yne - 1])
				{
					if (qest[xne][yne][dirt] == -1)
					{
						qest[xne][yne][dirt] = qest[xt][yt][dirt] + 1;
						que.push((xne) * 10000 + yne * 100 + dirt);
					}
				}
			}
		}
		if (qest[xt][yt][(dirt + 1) % 4] == -1)
		{
			qest[xt][yt][(dirt + 1) % 4] = qest[xt][yt][dirt] + 1;
			que.push(xt * 10000 + yt * 100 + (dirt + 1) % 4);
		}
		if (qest[xt][yt][(dirt + 3) % 4] == -1)
		{
			qest[xt][yt][(dirt + 3) % 4] = qest[xt][yt][dirt] + 1;
			que.push(xt * 10000 + yt * 100 + (dirt + 3) % 4);
		}
		que.pop();
	}
	cout << "-1";
	
	return 0;
}