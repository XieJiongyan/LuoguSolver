#include <iostream>
#include <array>
#include <algorithm>
using namespace::std;

constexpr int kmz{ 3003 };

struct sted {
  int t;
  int w;
  int nex;
};
array<sted, kmz> edge{};
array<int, kmz> node{};
void add_e(int it, int u, int v, int w) {
  edge[it].t = v, edge[it].w = w, edge[it].nex = node[u];
  node[u] = it;
}
int lne{ 0 };

int dp[kmz][kmz]{};
int n{}, m{};
array<int, kmz> ause{};

int dfs(int _nod) {
  if (_nod > n - m) {
    dp[_nod][1] = ause[_nod];
    return 1;
  }
  int lssu{ 0 }, lste{};
  for (auto i1(node[_nod]); i1; i1 = edge[i1].nex) {
    lste = dfs(edge[i1].t);
    lssu += lste;
    for (auto i2(lssu); i2; i2--) for (auto i3(0); i3 <= min(lste, i2); i3++) dp[_nod][i2] = max(dp[_nod][i2], dp[_nod][i2 - i3] + dp[edge[i1].t][i3] - edge[i1].w);
  }
  return lssu;
}

signed main() {
  for (auto& i1 : dp) for (auto& i2 : i1) i2 = ~0x7000ffff;
  cin >> n >> m;
  int k{}, nodc{}, wc{};
  for (auto i1(0); i1 < n - m; i1++) {
    cin >> k;
    for (auto i2(0); i2 < k; i2++) {
      cin >> nodc >> wc;
      add_e(++lne, i1 + 1, nodc, wc);
    }
  }
  for (auto i1(n - m + 1); i1 <= n; i1++) cin >> ause[i1];
  for (auto i1(1); i1 <= n; i1++) dp[i1][0] = 0;
  dfs(1);
  for (auto i1(m); i1 >= 1; i1--) if (dp[1][i1] >= 0) {
    cout << i1 << endl;
    break;
  }
  return 0;
}