#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;
#define int long long
inline int read() {
  int X = 0, w = 0; char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
constexpr int sz{ 1003 };
constexpr int range{ 20004 };
constexpr int drange{ 2 * range };

int h[sz];
array< array<bool, drange>, sz> vis{ false };
bool vis_later[sz][drange]{ false };
int dp[sz][drange]{ 0 };
int mod{ 998244353 };

signed main() {
  int n;
  int ans{ 0 };
  cin >> n;
  for (auto i(0); i < n; i++) {
    cin >> h[i];
  }
  for (auto in(0); in != n; in++) {
    for (auto ibefore(in - 1); ibefore >= 0; ibefore--) {
      auto commondif{ h[in] - h[ibefore] + range};
      if (!vis[ibefore][commondif]) {
        vis[ibefore][commondif] = true;
        dp[ibefore][commondif]++;
      }
      ans = (ans + dp[ibefore][commondif]) % mod;
      dp[in][commondif] = (dp[in][commondif] + dp[ibefore][commondif]) % mod;
      //if (!vis_later[in][commondif]) {
      //  vis_later[in][commondif] = true;
      //  dp[in][commondif] += 1;
      //}
    }
  }
  cout << ans + n << endl;
  return 0;
}
