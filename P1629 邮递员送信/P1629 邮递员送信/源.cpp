#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace::std;

struct edge {
  int to, next, weight;
  edge() = default;
  edge(int ft, int fn, int fw) : to(ft), next(fn), weight(fw) {}
};
struct node {
  int dis, edge;
  bool vis;
};
vector<edge> vsedge{ edge{0, 0, 0} };
vector<edge> vaedge{ edge{0, 0, 0} };
vector<node> vsnode(1);
vector<node> vanode(1);
void add_edge(int from, int to, int weight) {
  vsedge.emplace_back(edge{ to, vsedge[vsnode[from].edge].next, weight });
  vaedge.emplace_back(edge{ from, vaedge[vanode[to].edge].next, weight });
  vsnode[from].edge = vsedge.size() - 1;
  vanode[to].edge = vaedge.size() - 1;
}
int n, m;
struct xnode {
  int node, dis;
  bool operator<(const xnode f) const { return dis < f.dis; }
  xnode() = default;
  xnode(int fn) : node(fn), dis(vsnode[fn].dis) {}
};
priority_queue<xnode> vxnode;
priority_queue<xnode> vxanode;

signed main() {
  cin >> n >> m;
  vsnode.resize(n + 1), vanode.resize(n + 1);
  int in1, in2, in3;
  for (auto i(0); i < m; i++) {
    cin >> in1 >> in2 >> in3;
    add_edge(in1, in2, in3);
  }
  for (auto &i : vsnode) i.dis = 0x1111ffff;
  vsnode[1].dis = 0;
  vxnode.push(xnode{ 1 });

