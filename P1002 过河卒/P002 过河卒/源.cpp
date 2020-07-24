#include <iostream>
#include <vector>

#define BAD -1

using std::vector;

bool check_bad(long, long, long, long);

int main(void)
{
	long n, m, x, y;
	vector< vector<long long> > board;
	std::cin >> n >> m >> x >> y;
	++n;
	++m;
	vector<long long> line(n, 0);
	for (auto i = 0; i < n; ++i)
		board.push_back(line);
		if (check_bad(n, m, x, y))
			board[x][y] = BAD;
		if (check_bad(n, m, x + 1, y + 2))
			board[x + 1][y + 2] = BAD;
		if (check_bad(n, m, x + 1, y - 2))
			board[x + 1][y - 2] = BAD;
		if (check_bad(n, m, x + 2, y + 1))
			board[x + 2][y + 1] = BAD;
		if (check_bad(n, m, x + 2, y - 1))
			board[x + 2][y - 1] = BAD;
		if (check_bad(n, m, x - 1, y + 2))
			board[x - 1][y + 2] = BAD;
		if (check_bad(n, m, x - 1, y - 2))
			board[x - 1][y - 2] = BAD;
		if (check_bad(n, m, x - 2, y + 1))
			board[x - 2][y + 1] = BAD;
		if (check_bad(n, m, x - 2, y - 1))
			board[x - 2][y - 1] = BAD;
	for(auto i = 0; i < n; ++i)
		for (auto i2 = board[i].begin(); i2 < board[i].end(); i2++)
		{
			long a = 0, b = 0;
			if (i == 0 || *(i2 - board[i].begin() + board[i-1].begin()) == BAD)
				b = 0;
			else
				b = *(i2 - board[i].begin() + board[i - 1].begin());
			if (i2 == board[i].begin() || *(i2 - 1) == BAD)
				a = 0;
			else
				a = *(i2 - 1);
			if (i == 0 && i2 == board[i].begin())
				*i2 = 1;
			else if (*i2 == BAD)
				continue;
			else
				*i2 = a + b;
		}
	std::cout << board[n - 1][m - 1] << std::endl;
	std::cin >> n;
}

bool check_bad(long n, long m, long cx, long cy)
{
	bool flag = true;
	if (cx > n || cx < 0)
		flag = false;
	if (cy > m || cy < 0)
		flag = false;
	return flag;
}