#include <iostream>
#include <array>
#include <algorithm>

using namespace::std;

constexpr int kmx{ 1003 }, kinf{ 0x7000ffff };

array<int, kmx> afat{}, afun{}, adis{}, adee{};

inline bool cmp(int x, int y) {
  return adee[x] > adee[y];
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n{};
  cin >> n;
  int in{};
  afat[0] = 0, adee[0] = 0, adis[0] = kinf, afun[0] = 0;
  for (auto i1(1); i1 < n; i1++) {
    cin >> in;
    afat[i1] = in - 1;
    adee[i1] = adee[afat[i1]] + 1;
    adis[i1] = kinf, afun[i1] = i1;
  }
  sort(afun.begin(), afun.end(), cmp);
  int ans{};
  for (auto i1(0); i1 < n; i1++) {
    int ithp{ afun[i1] }, itpa{ afat[afat[afun[i1]]] };
    adis[ithp] = min(adis[ithp], min(adis[afat[ithp]] + 1, adis[itpa] + 2));
    if (adis[ithp] > 2) {
      adis[ithp] = 2;
      adis[itpa] = 0;
      ans++;
      adis[afat[itpa]] = min(adis[afat[itpa]], 1);
      adis[afat[afat[itpa]]] = min(adis[afat[afat[itpa]]], 2);
    }
  }
  cout << ans << endl;
  return 0;
}