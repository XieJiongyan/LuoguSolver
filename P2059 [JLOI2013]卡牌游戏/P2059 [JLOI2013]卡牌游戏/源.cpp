#include <iostream>
#include <vector>
#include <cstdio>

constexpr int kms(51);

using namespace::std;

double mat[kms][kms] = { 0 };

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (auto& i1 : v) cin >> i1;
  mat[1][0] = 1.0;
  for (auto i1 = 2; i1 <= n; i1++) {
    vector<int> vn(i1, 0);
    for (auto i2 : v) vn[(i2 - 1) % i1]++;
    for (auto i2 = 0; i2 < i1; i2++) for (auto i3 = 0; i3 < i1; i3++)
      if (i3 < i2) mat[i1][i3] += mat[i1 - 1][i3 + i1 - i2 - 1] * vn[i2] / m;
      else if (i3 > i2) mat[i1][i3] += mat[i1 - 1][i3 - i2 - 1] * vn[i2] / m;
  }
  for (auto i1 = mat[n]; i1 < mat[n] + n; i1++) printf("%.2f%% ", 100 * *i1);
  return 0;
}