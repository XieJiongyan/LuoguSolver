#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace::std;
#define int long long

struct edge {
  int to, next, weight;
  edge(int fto, int fnext, int fweight) : to(fto), next(fnext), weight(fweight) {}
  edge() = default;
};
vector<edge> vsedge(2);
struct node {
  int edge, money;
  int vis, dis;
};
vector<node> vsnode(1);
void add_edge(int from, int to, int weight) {
  vsedge.push_back(edge{ to, vsnode[from].edge, weight });
  vsnode[from].edge = vsedge.size() - 1;
}
int kn, km, kb;
int slmax, slmin, slmid;//(]
int sxmax;

struct xnode {
  int node, dis;
  xnode(int fn) : node(fn), dis(vsnode[fn].dis) {}
  xnode() = default;
  bool operator< (const xnode& f) const { return dis > f.dis; }
};
priority_queue<xnode> hxnode;

void Init() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin >> kn >> km >> kb;
  vsnode.resize(kn + 1); vsedge.reserve(2 * km + 2);
  int kai, kbi, kci;
  for (auto i(1); i <= kn; i++) {
    cin >> vsnode[i].money;
    slmax = max(slmax, vsnode[i].money);
  }
  ++slmax; sxmax = slmax;
  slmin = max(vsnode[1].money, vsnode[kn].money);
  slmin--;
  for (auto i(0); i < km; i++) {
    cin >> kai >> kbi >> kci;
    add_edge(kai, kbi, kci); add_edge(kbi, kai, kci);
  }
}
void solve() {
  while (slmin + 1 < slmax) {
    slmid = (slmin + slmax) >> 1;
    for (auto& snode : vsnode) snode.vis = false, snode.dis = 0x3333ffff;
    vsnode[1].dis = 0;
    hxnode.push(xnode{ 1 });
    while (!hxnode.empty()) {
      auto& ssthn(vsnode[hxnode.top().node]); hxnode.pop();
      if (ssthn.vis) continue;
      ssthn.vis = true;
      for (auto ie(ssthn.edge); ie; ie = vsedge[ie].next) {
        auto& ssnen(vsnode[vsedge[ie].to]);
        if (ssnen.money <= slmid && ssnen.dis > ssthn.dis + vsedge[ie].weight) {
          ssnen.dis = ssthn.dis + vsedge[ie].weight;
          hxnode.push(xnode{ vsedge[ie].to });
        }
      }
    }
    if (vsnode[kn].dis <= kb) slmax = slmid;
    else slmin = slmid;
  }
  if (slmax == sxmax) cout << "AFK" << endl;
  else cout << slmax << endl;
}
signed main() {
  Init();
  solve();
  return 0;
}