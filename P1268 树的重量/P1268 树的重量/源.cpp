#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace::std;

array< array<int, 30>, 30> arr{};

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  int in;
  do {
    cin >> in;
    for (auto i(0); i < in - 1; i++) for (auto i2(i + 1); i2 < in; i2++) {
      cin >> arr[i][i2];
      arr[i2][i] = arr[i][i2];
    }
    int ans{ arr[0][1] };
    for (auto i1(2); i1 < in; i1++) {
      int add{ 0x3333ffff };
      for (auto i2(1); i2 < i1; i2++) add = min(add, (arr[0][i1] + arr[i2][i1] - arr[0][i2]) >> 1);
      ans += add;
    }
    if (in) cout << ans << endl;
  } while (in);
  return 0;
}