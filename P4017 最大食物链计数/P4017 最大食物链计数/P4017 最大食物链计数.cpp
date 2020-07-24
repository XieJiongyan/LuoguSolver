#include <iostream>
#include <algorithm>
#include <vector>
using namespace::std;

struct edge {
  int to, next;
  edge(int ft, int fn) : to(ft), next(fn) {}
  edge() = default;
};
vector<edge> vedge(1);
struct node {
  long long eaten;
  int edge;
  bool dfsed;
  node(long long fe, int fd) : eaten(fe), edge(fd), dfsed(false) {}
  node() : eaten(0), edge(0), dfsed(false) {}
};
vector<node> vnode(1);
void add_edge(int ffrom, int fto) {
  vedge.emplace_back(edge{ fto, vnode[ffrom].edge });
  vnode[ffrom].edge = vedge.size() - 1;
}

vector<int> retopo;

void dfs(int inode) {
  if (vnode[inode].dfsed)
    return;
  for (auto ie = vnode[inode].edge; ie; ie = vedge[ie].next) {
    dfs(vedge[ie].to);
  }
  retopo.emplace_back(inode);
  vnode[inode].dfsed = true;
}
constexpr long long mod{ 80112002 };
signed main() {
  int n{}, m{};
  cin >> n >> m;
  vnode.resize(n + 1);
  for (int i{ 0 }; i < m; i++) {
    int from, to;
    cin >> from >> to;
    add_edge(from, to);
  }
  for (int in{ 1 }; in <= n; in++)
    if (!vnode[in].dfsed)
      dfs(in);
  for (auto i(retopo.rbegin()); i < retopo.rend(); i++) {
    int in = *i;
    if (vnode[in].eaten == 0)
      vnode[in].eaten = 1;
    for (auto ie = vnode[in].edge; ie; ie = vedge[ie].next) {
      vnode[vedge[ie].to].eaten = (vnode[vedge[ie].to].eaten + vnode[in].eaten) % mod;
    }
  }
  long long ans{ 0 };
  for (int in{ 1 }; in <= n; in++) {
    if (vnode[in].edge == 0) {
      ans = (ans + vnode[in].eaten) % mod;
    }
  }
  cout << ans;
  return 0;
}