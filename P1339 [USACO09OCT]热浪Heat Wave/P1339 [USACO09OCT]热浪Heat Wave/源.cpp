#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <string>
using namespace::std;

struct edge {
  int to, next, weight;
  edge() = default;
  edge(int fto, int fnext, int fweight) : to(fto), next(fnext), weight(fweight) {}
};
vector<edge> vsedge(2);
struct node {
  int mldis, miedge;
  bool vis;
  bool operator< (const node& f) { return mldis < f.mldis; }
  node() : miedge(0), mldis{ 0x3333ffff }, vis{ false }{}
};
vector<node> vsnode(1);
void add_edge(int fifrom, int fito, int fiweight) {
  vsedge.emplace_back(edge(fito, vsnode[fifrom].miedge, fiweight));
  vsnode[fifrom].miedge = vsedge.size() - 1;
}
int kln, klm, kis, kit;
struct xnode {
  int minode; int mldis;
  xnode(int fnode) : minode(fnode), mldis(vsnode[fnode].mldis) {}
  bool operator< (const xnode& f) const { return mldis > f.mldis; }
};
priority_queue<xnode> hinode;

void Init() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin >> kln >> klm >> kis >> kit;
  //fstream fin("P1339_2.in.txt");
  //fin >> kln >> klm >> kis >> kit;
  vsedge.reserve(2 * klm + 2);
  vsnode.resize(kln + 1);
  int kiu, kiv, klw;
  for (auto i(0); i < klm; i++) {
    cin >> kiu >> kiv >> klw;
    //fin >> kiu >> kiv >> klw;
    add_edge(kiu, kiv, klw);
    add_edge(kiv, kiu, klw);
  }
  vsnode[kis].mldis = 0;
}
void solve() {
  hinode.push(kis);
  while (!hinode.empty()) {
    auto& ssthn(vsnode[hinode.top().minode]); hinode.pop();
    if (ssthn.vis) continue;
    ssthn.vis = true;
    for (auto ie(ssthn.miedge); ie; ie = vsedge[ie].next) {
      auto& ssnen(vsnode[vsedge[ie].to]);
      if (ssnen.mldis > ssthn.mldis + vsedge[ie].weight) {
        ssnen.mldis = ssthn.mldis + vsedge[ie].weight;
        hinode.push(vsedge[ie].to);
      }
    }
  }
  cout << vsnode[kit].mldis << endl;
}
signed main() {
  Init();
  solve();
  return 0;
}