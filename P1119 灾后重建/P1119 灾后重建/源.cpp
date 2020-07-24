#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace::std;

constexpr int arrsize{ 200 };
array< array<int, arrsize>, arrsize> afloyd{};
int n, m, q;
vector<int> ntime{};

void update(int time) {
  for (auto i(0); i < n; i++) for (auto j(0); j < n; j++) afloyd[i][j] = min(afloyd[i][j], afloyd[i][time] + afloyd[time][j]);
}
signed main() {
  cin >> n >> m;
  ntime.resize(n);
  for (auto &i : ntime) cin >> i;
  int in1, in2, in3;
  for (auto &i : afloyd) for (auto &i2 : i) i2 = 0x11110000;
  for (auto i(0); i < n; i++) afloyd[i][i] = 0;
  for (auto i(0); i < m; i++) {
    cin >> in1 >> in2 >> in3;
    afloyd[in1][in2] = afloyd[in2][in1] = in3;
  }
  cin >> q;
  int itntime(0);
  for (auto i(0); i < q; i++) {
    cin >> in1 >> in2 >> in3;
    for (; itntime < n && ntime[itntime] <= in3; itntime++)
      update(itntime);
    if (afloyd[in1][in2] == 0x11110000 || ntime[in1] > in3 || ntime[in2] > in3) cout << -1 << endl;
    else cout << afloyd[in1][in2] << endl;
  }
  return 0;
}