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

constexpr int sz{ 100005 };
int a[sz], b[sz];
int dp[sz]{ 0 };
int place_a[sz], c[sz];

signed main() {
  int n;
  cin >> n;
  for (int i(0); i < n; i++) {
    cin >> a[i];
    place_a[a[i]] = i;
  }
  for (int i(0); i < n; i++) {
    cin >> b[i];
    c[i] = place_a[b[i]];
  }
  //for (int i(0); i < n; i++) {
  //  dp[i] = 0x1111ffff;
  //}
  dp[0] = c[0];
  int len{ 0 };
  for (int i(1); i < n; i++) {
    if (c[i] > dp[len]) {
      len++;
      dp[len] = c[i];
    }
    else {
      *lower_bound(dp, dp + len, c[i]) = c[i];
    }
  }
  cout << len + 1 << endl;
  return 0;
}
