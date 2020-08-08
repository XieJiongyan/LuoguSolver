#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
#define int long long
inline int read() {
  int X = 0, w = 0; char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
constexpr int stlist_sz{ 100005 };
constexpr int log_stlist_sz{ 27 };
int stlist[stlist_sz][log_stlist_sz];
int a[stlist_sz]{ 0 };
void initialize_stlist(int stlist_real_sz) {
  for (int j(1); j <= log_stlist_sz; j++)
    for (int i(1); i + (1 << j) - 1 <= stlist_real_sz; i++)
      stlist[i][j] = max(stlist[i][j - 1], stlist[i + (1 << (j - 1))][j - 1]);
}
int stlist_query(int l, int r) {
  int k = log2(r - l + 1);
  return max(stlist[l][k], stlist[r - (1 << k) + 1][k]);
}
signed main() {
  int n, m;
  cin >> n >> m;
  for (auto i(1); i <= n; i++)
    a[i] = read();
  for (auto i(1); i <= n; i++)
    stlist[i][0] = a[i];
  initialize_stlist(n);
  int l, r;
  while (m--) {
    l = read();
    r = read();
    printf("%d\n", stlist_query(l, r));
  }
  return 0;
}
