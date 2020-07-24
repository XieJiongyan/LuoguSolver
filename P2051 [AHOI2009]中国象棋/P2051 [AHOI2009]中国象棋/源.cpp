#include <iostream>
using namespace::std;
#define int long long

constexpr int kmx{ 103 }, mod{ 9999973 };
int dp[kmx][kmx][kmx]{};

signed main() {
  int n, m;
  cin >> n >> m;
  dp[0][0][0] = 1;
  if (m >= 1) dp[0][0][1] = m;
  if (m >= 2) dp[0][0][2] = m * (m - 1) / 2;
  for (auto i1(1); i1 < n; i1++) for (auto i2(0); i2 <= m; i2++) for (auto i3(0); i3 + i2 <= m; i3++) {
    auto& thup{ dp[i1][i2][i3] };
    auto& ll{ dp[i1 - 1] };
    thup += ll[i2][i3];
    if (i2) thup += ll[i2 - 1][i3 + 1] * (i3 + 1);
    if (i3) thup += ll[i2][i3 - 1] * (m - i2 - i3 + 1);
    if (i2 >= 2) thup += ll[i2 - 2][i3 + 2] * (i3 + 2) * (i3 + 1) / 2;
    if (i3 >= 2) thup += ll[i2][i3 - 2] * (m - i2 - i3 + 2) * (m - i2 - i3 + 1) / 2;
    if (i2 && i3) thup += ll[i2 - 1][i3] * i3 * (m - i2 - i3 + 1);
    thup %= mod;
  }
  int lans{ 0 };
  for (auto& i1 : dp[n - 1]) for (auto& i2 : i1) lans = (lans + i2) % mod;
  cout << lans;
  return 0;
}