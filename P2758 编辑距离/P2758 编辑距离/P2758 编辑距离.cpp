#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
#define int long long
inline int read() {
  int X = 0, w = 0; char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}

int dp[2001][2001]{ 0 };
signed main() {
  string a, b;
  cin >> a >> b;
  auto a_size(a.size()), b_size(b.size());
  for (auto i1(1); i1 <= a_size; i1++) {
    for (auto i2(1); i2 <= b_size; i2++) {
      dp[i1][i2] = 0x1111ffff;
    }
  }
  for (auto i(1); i <= max(a_size, b_size); i++) {
    dp[i][0] = dp[0][i] = i;
  }
  for (auto i1(1); i1 <= a_size; i1++) {
    for (auto i2(1); i2 <= b_size; i2++) {
      int change{ a[i1 - 1] == b[i2 - 1] ? 0 : 1 };
      dp[i1][i2] = min(dp[i1][i2], dp[i1 - 1][i2 - 1] + change);
      dp[i1][i2] = min(dp[i1][i2], dp[i1 - 1][i2] + 1);
      dp[i1][i2] = min(dp[i1][i2], dp[i1][i2 - 1] + 1);
    }
  }
  cout << dp[a_size][b_size] << endl;
  return 0;
}
