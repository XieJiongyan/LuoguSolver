#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;
typedef long long ll;
#define int long long
inline int read() {
  int X = 0, w = 0; char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}

constexpr int sz{ 32 };
array<int, sz> score;
int max_score[sz][sz]{ 0 };
int root[sz][sz]{ 0 };

void vlr(int l, int r) {
  if (l == r)
    return;
  int t_root{ root[l][r] };
  cout << t_root << ' ';
  vlr(l, t_root);
  vlr(t_root + 1, r);
}
signed main() {
  int n;
  cin >> n;
  for (auto i(1); i <= n; i++)
    cin >> score[i];
  for (auto& a : max_score) 
    for (auto& s : a) {
      s = 1;
    }
  for (auto gap(1); gap <= n; gap++) 
    for (auto l(1); l + gap <= n + 1; l++) {
      int r{ l + gap };//[l, r)
      int nwvalue{ 0 };
      if (gap == 1) {
        max_score[l][r] = score[l];
        root[l][r] = l;
        continue;
      }
      for (auto mid(l); mid < r; mid++) {
        nwvalue = max_score[l][mid] * max_score[mid + 1][r] + score[mid];
        if (nwvalue > max_score[l][r]) {
          max_score[l][r] = nwvalue;
          root[l][r] = mid;
        }
      }
    }
  cout << max_score[1][n + 1] << endl;
  vlr(1, n + 1);
  return 0;
}
