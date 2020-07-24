#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

struct node {
  int minext;
  int micolor;
  int mldfn;
  int mlsucdfn;
  int mlcircle;
  node(int finext) : minext(finext), micolor(0), mldfn(0), mlsucdfn(0), mlcircle(0) {}
  node() = default;
  node(const node&) = default;
};

int kln{};
vector<node> vsnode(1);

void Init() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin >> kln;
  vsnode.reserve(kln + 1);
  int in{};
  for (int i(0); i < kln; i++) {
    cin >> in;
    vsnode.emplace_back(in);
  }
}
void solve() {
  for (auto i1(1); i1 <= kln; i1++)
    for (auto i2(i1), slcnt(0); i2; i2 = vsnode[i2].minext, slcnt++) {
      auto& ssthn(vsnode[i2]);
      if (!ssthn.micolor) {
        ssthn.micolor = i1;
        ssthn.mldfn = slcnt;
      }
      else if (ssthn.micolor == i1) {
        cout << slcnt << endl;
        vsnode[i1].mlsucdfn = ssthn.mldfn;
        vsnode[i1].mlcircle = slcnt - ssthn.mldfn;
        break;
      }
      else {
        vsnode[i1].mlsucdfn = max(vsnode[ssthn.micolor].mlsucdfn - ssthn.mldfn, 0) + slcnt;
        vsnode[i1].mlcircle = vsnode[ssthn.micolor].mlcircle;
        cout << vsnode[i1].mlsucdfn + vsnode[i1].mlcircle << endl;
        break;
      }
    }
}
signed main() {
  Init();
  solve();
  return 0;
}