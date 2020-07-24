#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;

struct edge {
  int t, nex;
  bool fsd;
  edge(int t_, int nex_) : t(t_), nex(nex_), fsd{ false } {}
  edge() = default;
};
vector<edge> vedg{ edge{0, 0}, edge{0x3f3f3f3f, 0x3f3f3f3f} };
struct node {
  int edg;
  int deg;
};
vector<node> vnod(64);
void add_edge(int from, int to) {
  vedg.emplace_back(edge{ to, vnod[from].edg });
  vnod[from].edg = vedg.size() - 1;
  vnod[from].deg++;
}

string tans{};

void dfs(int inod) {
  int imnx = 1;
  for (auto i1(vnod[inod].edg); i1; i1 = vedg[i1].nex) if (!vedg[i1].fsd && vedg[i1].t < vedg[imnx].t) imnx = i1;
  if (imnx != 1) {
    vedg[imnx | 1].fsd = true;
    vedg[(imnx >> 1) << 1].fsd = true;
    vnod[inod].deg--;
    vnod[vedg[imnx].t].deg--;
    dfs(vedg[imnx].t);
  }
  tans.push_back(static_cast<char>('A' + inod - 1));
  if (vnod[inod].deg) {
    tans.pop_back();
    dfs(inod);
  }
}
signed main() {
  int n;
  cin >> n;
  string tin;
  for (auto i1 = 0; i1 < n; i1++) {
    cin >> tin;
    add_edge(tin[0] - 'A' + 1, tin[1] - 'A' + 1);
    add_edge(tin[1] - 'A' + 1, tin[0] - 'A' + 1);
  }
  vector<int> vodn{};
  for (auto& i1 : vnod) if (i1.deg & 1) {
    vodn.emplace_back(&i1 - &vnod[0]);
    if (vodn.size() >= 3) {
      cout << "No Solution" << endl;
      exit(0);
    }
  }
  if (vodn.empty()) for (auto& i1 : vnod) if (i1.deg) {
      dfs(&i1 - &vnod[0]);
      break;
    }
    else continue;
  else dfs(min(vodn[0], vodn[1]));
  if (tans.size() == n + 1) for (auto i1(tans.rbegin()); i1 < tans.rend(); i1++) cout << *i1;
  else
    cout << "No Solution" << endl;
  return 0;
}