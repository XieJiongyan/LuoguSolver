#include <iostream>
#include <cstdio>

using namespace::std;

signed main() {
  int n{};
  cin >> n;
  double lmh{ 4200.0 * 100 / n }, lans{ 0 };
  for (auto i1 = 1; i1 <= n; i1++) {
    lans += lmh;
    lmh = lmh * (1 - 1.0 / 2 / i1);
  }
  printf("%.2lf", lans);
  return 0;
}