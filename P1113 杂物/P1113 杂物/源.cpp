#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

int n;
vector<int> v;

signed main() {
  cin >> n;
  v.resize(n + 1);
  int in, time;
  for (auto i(1); i <= n; i++) {
    cin >> in >> time;
    do {
      cin >> in;
      v[i] = max(v[i], v[in]);
    } while (in != 0);
    v[i] += time;
  }
  cout << *max_element(v.begin(), v.end()) << endl;
  return 0;
}