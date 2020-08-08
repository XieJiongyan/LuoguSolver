#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define int long long
inline int read() {
  int X = 0, w = 0; char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
constexpr int sz{ 5555 };
int dp[sz][sz]{ 0 };//dp[n][w];
int a[sz]{ 0 };
signed main() {
  int n, w, s;
  cin >> n >> w >> s;
  for (auto i(1); i <= n; i++)
    cin >> a[i];
  for (auto in(0); in <=n; in++)
    for (auto iw(0); iw <= w; iw++) {
      dp[in][iw] = -0x777788887777ffff;
    }
  dp[0][0] = 0;
  int l{}, r{};
  for (auto in(1); in <= n; in++) {
    priority_queue<
    for (auto iw(1); iw <= w; iw++) {
      l =  iw - 1;
      r =  min(iw + s - 1, w);
      dp[in][iw] = *max_element(dp[in - 1] + l, dp[in - 1] + r + 1) + iw * a[in];
    }
  }
  cout << *max_element(dp[n], dp[n] + w + 1);
  return 0;
}
