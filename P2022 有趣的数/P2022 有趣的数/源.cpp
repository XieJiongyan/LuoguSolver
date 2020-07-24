#include <iostream>
#include <string>

#define int long long

using namespace::std;

signed main() {
  int n{}, k{}, m{};
  cin >> k >> m;
  string sk{ to_string(k) };
  int lep{ 0 }, shk{ 0 }, tenp{ 1 };
  for (auto i1(sk.begin()); i1 < sk.end(); i1++) {
    shk = shk * 10 + (*i1 - '0');
    lep += shk - tenp + 1;
    n += shk - tenp + 1;
    tenp *= 10;
    if (i1 != sk.end() - 1) n += tenp - shk - 1;
  }
  if (m < lep) {
    cout << 0 << endl;
    return 0;
  }
  if (m == lep) {
    cout << n << endl;
    return 0;
  }
  if (k * 10 == tenp) {
    cout << 0 << endl;
    return 0;
  }
  n--;
  for (; ; tenp *= 10) {
    if (m <= lep) {
      cout << n - (lep - m) << endl;
      return 0;
    }
    n += tenp - shk;
    shk *= 10;
    lep += shk - tenp;
    n += shk - tenp;
  }
  return 0;
}