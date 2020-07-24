#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

struct edge {
  int to, next, weight, from;
  edge(int ft, int fn, int fw, int ff) : to(ft), next(fn), weight(fw), from(ff) {}
  edge() = default;
};
vector<edge> vsedge{ edge{0, 0, 0x3333fff, 0}, edge{0, 0, 0x3333ffff, 0} };
struct node {
  int edge, uni;
};
vector<node> vsnode(1);
int find(int fnode) {
  if (vsnode[fnode].uni == fnode) return fnode;
  else return vsnode[fnode].uni = find(vsnode[fnode].uni);
}
void add_edge(int ff, int ft, int fw) {
  vsedge.emplace_back(edge{ ft, vsnode[ff].edge, fw , ff});
  vsnode[ff].edge = vsedge.size() - 1;
}
struct xedge {
  int edge, weight;
  bool operator< (xedge f) const {
    return weight < f.weight;
  }
  xedge(int fe) : edge(fe), weight(vsedge[fe].weight) {}
};
vector<xedge> vxedge;
int kn;
int slfinish{ 0 }, cntxe{ 0 }, slans{ 0 };

void Init() {
  cin >> kn;
  vsnode.resize(kn + 1); vsedge.reserve(kn * kn + 2);
  int in;
  for (auto i1(0); i1 < kn; i1++) for (auto i2(0); i2 < kn; i2++) {
    cin >> in;
    if (i1 < i2) {
      add_edge(i1 + 1, i2 + 1, in);
      add_edge(i2 + 1, i1 + 1, in);
      vxedge.emplace_back(xedge(vsedge.size() - 1));
    }
  }
  for (auto& sn : vsnode) sn.uni = &sn - &vsnode[0];
}
void solve() {
  sort(vxedge.begin(), vxedge.end());
  while (slfinish < kn - 1) {
    auto& ssthe(vsedge[vxedge[cntxe++].edge]);
    if (find(ssthe.from) != find(ssthe.to)) {
      slfinish++;
      slans += ssthe.weight;
      vsnode[find(ssthe.from)].uni = find(ssthe.to);
    }
  }
  cout << slans << endl;
}
signed main() {
  Init();
  solve();
  return 0;
}