#include <iostream>
#include <algorithm>

using namespace::std;

int main() {
  long long n(0), k(0);
  cin >> n >> k;
  long long itl(1), itr(0);
  long long ans = n * k;
  while (itr < n + 1 && k / itl) {
    itr = min(k / (k / itl), n) + 1;
    ans -= (k / itl) * (itr - itl) * (itl + itr - 1) / 2;
    itl = itr;
  }
  cout << ans << endl;
  return 0;
}