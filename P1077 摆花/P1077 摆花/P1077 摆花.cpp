#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define int long long
inline int read() {
  int X = 0, w = 0; char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}

constexpr int sz{ 102 };
int dp[sz][sz]{ 0 };
int a[sz]{ 0 };
constexpr int mod{ 1000007 };
signed main() {
  int n, m;
  cin >> n >> m;
  for (auto in(1); in <= n; in++)
    cin >> a[in];
  dp[0][0] = 1;
  for (auto in(1); in <= n; in++) {
    for (auto im(m); im >= 0; im--) {
      dp[in][im] += dp[in - 1][im];
      for (auto num_flower(1); num_flower <= a[in] && im - num_flower >= 0; num_flower++) {
        dp[in][im] += dp[in - 1][im - num_flower];
      }
      dp[in][im] %= mod;
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
