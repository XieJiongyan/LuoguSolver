#include <iostream>
#include <algorithm>
#include <array>
#include <map>
#include <vector>

using namespace::std;

constexpr int kasz = 1000006;

array<int, kasz> abit = {};

inline void ins_bit(int poi, int val) {
  for (; poi < kasz; poi += poi & -poi) abit[poi] += val;
}

inline int query_bit(int l, int r) {
  l--, r--;
  int lans = 0;
  for (; r > 0; r -= r & -r) lans += abit[r];
  for (; l > 0; l -= l & -l) lans -= abit[l];
  return lans;
}

array<int, kasz> avap = {};

struct St {
  int _l, _r;
  int _it;
  bool operator<(St st) { return _r < st._r; };
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int ln = 0;
  cin >> ln;
  vector<int> vpea(ln + 1);
  for (auto i1 = 1; i1 < ln + 1; i1++) cin >> vpea[i1];
  int lm = 0;
  cin >> lm;
  vector<St> vque(lm);
  vector<int> vans(lm);
  for (auto i1 = 0; i1 < lm; i1++) {
    cin >> vque[i1]._l >> vque[i1]._r;
    vque[i1]._it = i1;
  }
  sort(vque.begin(), vque.end());
  int itpe = 1;
  for (auto i1 = 0; i1 < lm; i1++) {
    for (; itpe < vque[i1]._r + 1; itpe++) {
      if (avap[vpea[itpe]] != 0) ins_bit(avap[vpea[itpe]], -1);
      avap[vpea[itpe]] = itpe;
      ins_bit(itpe, 1);
    }
    vans[vque[i1]._it] = query_bit(vque[i1]._l, vque[i1]._r + 1);
  }
  for (auto i1 : vans)
    cout << i1 << endl;
  return 0;
}