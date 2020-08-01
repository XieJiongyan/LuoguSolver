#include <iostream>
#include <algorithm>
#include <vector>
using namespace::std;

signed main() {
  int t{}, m{};
  cin >> t >> m;
  t++;
  vector<int> a(m);
  vector<int> b(m);
  vector<int> dp(t, 0);
  for (auto i(0); i < m; i++) {
    cin >> a[i] >> b[i];
  }
  for (auto im(0); im < m; im++) {
    for (auto it(a[im]); it < t; it++) {
      dp[it] = max(dp[it], dp[it - a[im]] + b[im]);
    }
  }
  cout << dp[t - 1] << endl;
  return 0;
}