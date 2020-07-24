#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

struct edge {
  int to, weight, next, from;
  edge(int ft, int fw, int fn, int ff) : to(ft), weight(fw), next(fn), from(ff) {}
  bool operator<(edge f) {
    return weight < f.weight;
  }
  edge() = default;
};
vector<edge> vsedge;
struct node {
  int uni, edge;
};
vector<node> vsnode(1);
int find(int f) {
  if (vsnode[f].uni == f) return f;
  else return vsnode[f].uni = find(vsnode[f].uni);
}
int n, m;
int krucnt;

void Init() {
  int u, v, c;
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin >> n >> m;
  vsnode.resize(n + 1);
  vsedge.reserve(m);
  for (auto i(0); i < m; i++) {
    cin >> u >> v >> c;
    vsedge.emplace_back(edge{ u, c, 0, v });
  }
  for (auto& in : vsnode) in.uni = &in - &vsnode[0];
}
void solve() {
  cout << n - 1 << " ";
  sort(vsedge.begin(), vsedge.end());
  for (auto& ie : vsedge) {
    auto &thn(vsnode[ie.to]), &nen(vsnode[ie.from]);
    if (find(&thn - &vsnode[0]) != find(&nen - &vsnode[0])) {
      vsnode[max(thn.uni, nen.uni)].uni = min(thn.uni, nen.uni);
      krucnt++;
    }
    if (krucnt == n - 1) {
      cout << ie.weight << endl;
      exit(0);
    }
  }
}
signed main() {
  Init();
  solve();
  return 0;
}