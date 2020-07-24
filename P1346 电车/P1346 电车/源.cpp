#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace::std;

struct edge {
  int to, next, weight;
  edge(int ft, int fn, int fw) : to(ft), next(fn), weight(fw) {}
  edge() : to(0), next(0), weight(0) {}
};
vector<edge> vsedge(1);
struct node {
  int edge, dis, vis;
  node() : dis(0x3333ffff), vis(false), edge(0) {}
};
vector<node> vsnode(1);
void add_edge(int ff, int ft, int fw) {
  vsedge.emplace_back(edge{ ft, vsnode[ff].edge, fw });
  vsnode[ff].edge = vsedge.size() - 1;
}
struct xnode {
  int node, dis;
  bool operator< (const xnode& f) const {
    return dis > f.dis;
  }
  xnode(int fn) : node(fn), dis(vsnode[fn].dis) {}
};
priority_queue<xnode> hxnode{};
int kn, ka, kb;

void Init() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin >> kn >> ka >> kb;
  vsnode.resize(kn + 1); vsedge.reserve(kb + 1);
  int k1, k2;
  for (auto i(1); i <= kn; i++) {
    cin >> k1;
    if (!k1) continue;
    cin >> k2;
    add_edge(i, k2, 0);
    for (auto i2(1); i2 < k1; i2++) {
      cin >> k2;
      add_edge(i, k2, 1);
    }
  }
  vsnode[ka].dis = 0;
}
void solve() {
  hxnode.emplace(xnode{ ka });
  while (!hxnode.empty()) {
    auto& ssthn(vsnode[hxnode.top().node]); hxnode.pop();
    if (ssthn.vis) continue;
    else ssthn.vis = true;
    for (auto ie(ssthn.edge); ie; ie = vsedge[ie].next) {
      auto& ssnen(vsnode[vsedge[ie].to]);
      if (ssnen.dis > ssthn.dis + vsedge[ie].weight) {
        ssnen.dis = ssthn.dis + vsedge[ie].weight;
        hxnode.emplace(vsedge[ie].to);
      }
    }
  }
  if (vsnode[kb].dis == 0x3333ffff) cout << -1 << endl;
  else cout << vsnode[kb].dis << endl;
}
signed main() {
  Init();
  solve();
  return 0;
}