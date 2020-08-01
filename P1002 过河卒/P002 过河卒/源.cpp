#include <iostream>
using namespace::std;
#define int long long 

int xp[2]{ 2, 1 };
int yp[2]{ 1, 2 };

int dmsion[2]{ -1 , 1 };
bool avai[31][31]{ false };
int dp[21][21]{ 0 };
signed main() {
  int n, m, hx, hy;
  cin >> n >> m >> hx >> hy;
  avai[hx][hy] = true;
  for (int ix : dmsion) {
    for (int iy : dmsion) {
      for (int ip(0); ip < 2; ip++) {
        int x_place = hx + ix * xp[ip];
        int y_place = hy + iy * yp[ip];
        if (x_place >= 0 && y_place >= 0) {
          avai[x_place][y_place] = true;
        }
      }
    }
  }
  dp[0][0] = 1;
  for (int ix(0); ix <= n; ix++) {
    for (int iy(0); iy <= m; iy++) {
      if (avai[ix][iy])
        continue;
      if (ix)
        dp[ix][iy] += dp[ix - 1][iy];
      if (iy)
        dp[ix][iy] += dp[ix][iy - 1];
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}