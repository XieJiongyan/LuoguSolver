#include <iostream>
#include <algorithm>
#include <vector>
using namespace::std;
#define int long long 

constexpr int th{ 1002 };
int dp[th][th]{ 0 };
int lose[th]{ 0 }, win[th]{ 0 }, use[th]{ 0 };

signed main() {
  int n, x;
  cin >> n >> x;
  for (auto i(1); i <= n; i++) {
    cin >> lose[i] >> win[i] >> use[i];
  }
  for (auto in(0); in <= n; in++) 
    for (auto ix(0); ix <= x; ix++) {
      if (in)
        dp[in][ix] = max(dp[in][ix], dp[in - 1][ix] + lose[in]);
      if (ix) 
        dp[in][ix] = max(dp[in][ix], dp[in][ix - 1]);
      if (in && ix >= use[in]) {
        dp[in][ix] = max(dp[in][ix], dp[in - 1][ix - use[in]] + win[in]);
      }
    }
  cout << dp[n][x] * 5<< endl;
  return 0;
}