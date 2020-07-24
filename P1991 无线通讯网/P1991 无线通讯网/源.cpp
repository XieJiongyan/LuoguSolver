#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
using namespace::std;

struct edge {
  int to, next, from;
  double weight;
  bool operator<(edge f) {
    return weight < f.weight;
  }
  edge(int ft, int fn, double fw, int ff) : to(ft), next(fn), weight(fw), from(ff) {}
  edge() = default;
};
vector<edge> vsedge{ edge{0, 0, 0.0, 0}, edge{0, 0, 0.0, 0} };
struct node {
  int edge, uni;
  int x, y;
  node() = default;
};
vector<node> vsnode(1);
void add_edge(int ff, int ft, double fw) {
  vsedge.emplace_back(edge{ ft, vsnode[ff].edge, fw, ff });
  vsnode[ff].edge = (vsedge.size() - 1);
}
int find(int f) {
  if (vsnode[f].uni == f) return f;
  else return vsnode[f].uni = find(vsnode[f].uni);
}
int s, p;
int krucnt{ 0 };

void Init() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin >> s >> p;
  //fstream fin("P1991_3.in.txt");
  //fin >> s >> p;
  vsnode.resize(p + 1); vsedge.resize(p * p * 2 + 2);
  int in1, in2;
  for (auto i(1); i <= p; i++) {
    cin >> vsnode[i].x >> vsnode[i].y;
    //fin >> vsnode[i].x >> vsnode[i].y;
    vsnode[i].uni = i;
  }
  for (auto i1(1); i1 <= p; i1++) for (auto i2(i1 + 1); i2 <= p; i2++) {
    double dis{ sqrt((vsnode[i1].x - vsnode[i2].x) * (vsnode[i1].x - vsnode[i2].x) + \
      (vsnode[i1].y - vsnode[i2].y) * (vsnode[i1].y - vsnode[i2].y)) };
    add_edge(i1, i2, dis); 
  }
}
void solve() {
  sort(vsedge.begin(), vsedge.end());
  auto lim{ p - s };
  auto i(0);
  for (; i < vsedge.size() && krucnt < lim; i++) {
    auto& nen(vsnode[vsedge[i].to]), &thn(vsnode[vsedge[i].from]);
    if (find(&nen - &vsnode[0]) != find(&thn - &vsnode[0])) {
      vsnode[max(thn.uni, nen.uni)].uni = min(thn.uni, nen.uni);
      krucnt++;
    }
  }
  printf("%.2f", vsedge[i - 1].weight);
}
signed main() {
  Init();
  solve();
  return 0;
}
    