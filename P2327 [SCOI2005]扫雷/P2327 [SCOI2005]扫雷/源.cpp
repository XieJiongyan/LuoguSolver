#include <iostream>
#include <vector>

using namespace::std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 0;
  cin >> n;
  vector<int> v(n);
  vector<int> vans(n, -1);
  int lans = 0;
  for (auto& i1 : v) cin >> i1;
  for (auto i1 = 0; i1 < 2; i1++) {
    vans[0] = i1;
    int lexe = v[0] - vans[0];
    bool brgt = true;
    for (auto i1 = 1; i1 < n; i1++) {
      if (lexe < 0 || lexe >= 2) {
        brgt = false;
        break;
      }
      vans[i1] = lexe;
      lexe = v[i1] - vans[i1] - vans[i1 - 1];
    }
    if (brgt && !lexe) lans++;
  }
  cout << lans << endl;
  return 0;
}