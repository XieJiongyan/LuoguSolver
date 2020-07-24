#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace::std;

struct edge {
  int t, nex, w;
  edge(int tin, int nexin, int win) : t(tin), nex(nexin), w(win) {}
  edge() = default;
};
vector<edge> vedg{edge(0, 0, 0)};
vector<int> vnod{};
void add_edge(int from, int to, int weight) {
  vedg.emplace_back(edge(to, vnod[from], weight));
  vnod[from] = vedg.size() - 1;
}

deque<bool> vusd{};
deque<bool> vcol{false};

int bfs(int fnod, int fcol) {
  queue<int> wqu{};
  wqu.emplace(fnod);
  int inde{};
  int lnot{ 0 }, lnof{ 0 };
  while (!wqu.empty()) {
    inde = wqu.front(); wqu.pop();
    auto& lncl(vcol[inde]);
    if (lncl) lnot++;
    else lnof++;
    vusd[inde] = true;
    for (auto i2(vnod[inde]); i2; i2 = vedg[i2].nex) {
      auto& it(vedg[i2].t);
      if (vusd[it]) continue;
      if (lncl && vcol[it]) return -1;
      if (!lncl) vcol[it] = true;
      wqu.emplace(it);
    }
  }
  return min(lnof, lnot);
}
signed main() {
  int n{}, m{};
  cin >> n >> m;
  vnod.resize(n + 1); vedg.reserve(2 * m);
  vusd.resize(n + 1); vcol.resize(n + 1);
  for (auto& i1 : vusd) i1 = false;
  int in1{}, in2{};
  for (auto i1(0); i1 < m; i1++) {
    cin >> in1 >> in2;
    add_edge(in1, in2, 1);
    add_edge(in2, in1, 1);
  }
  int lans{}, lansc{};
  for (auto i1(1); i1 < n + 1; i1++) if (!vusd[i1]) if ((lansc = bfs(i1, true)) == -1) {
    cout << "Impossible" << endl;
    exit(0);
  }
  else lans += lansc;
  cout << lans << endl;
  return 0;
}