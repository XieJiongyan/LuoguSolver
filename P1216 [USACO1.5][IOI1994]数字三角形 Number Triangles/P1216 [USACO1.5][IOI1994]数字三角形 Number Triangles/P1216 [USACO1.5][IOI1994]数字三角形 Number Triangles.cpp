#include <iostream>
#include <algorithm>
#include <array>
using namespace::std;

constexpr int max_size{ 1000 };
array< array<int, max_size>, max_size> m;

signed main() {
  int r{};
  cin >> r;
  for (int i{ 0 }; i < r; i++) {
    for (int i2{ 0 }; i2 <= i; i2++) {
      cin >> m[i][i2];
      if (i) {
        m[i][i2] += max(m[i - 1][i2], m[i - 1][max(i2 - 1, 0)]);
      }
    }
  }
  cout << *max_element(m[r - 1].begin(), m[r - 1].end()) << endl;
  return 0;
}