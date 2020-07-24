#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace::std;

struct node {
  int uni;
  char type;
};
vector<node> auni{};
int n, m;
int find(int x) {
  if (auni[x].uni == x) return x;
  else return auni[x].uni = find(auni[x].uni);
}
string s;

signed main() {
  cin >> n >> m;
  auni.resize(n + 1);
  for (auto i(1); i <= n; i++) {
    auni[i].uni = i;
    cin >> auni[i].type;
  }
  int in1, in2;
  for (auto i(0); i < n - 1; i++) {
    cin >> in1 >> in2;
    if (find(in1) != find(in2) && auni[in1].type == auni[in2].type)
      auni[max(auni[in1].uni, auni[in2].uni)].uni = min(auni[in1].uni, auni[in2].uni);
  }
  char in3;
  for (auto i(0); i < m; i++) {
    cin >> in1 >> in2 >> in3;
    if (find(in1) == find(in2) && in3 != auni[in1].type) cout << 0;
    else cout << 1;
  }
  return 0;
}