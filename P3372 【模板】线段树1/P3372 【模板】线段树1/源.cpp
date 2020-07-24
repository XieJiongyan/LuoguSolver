#include <iostream>
#include <array>
#include <vector>

using namespace::std;

constexpr long long karr_sz = 100005;

array<long long, karr_sz> ain{};
array<long long, karr_sz << 2> seg{};
array<long long, karr_sz << 2> aam{};

void push_seg(int p, int l, int r) {
  int m = l + r >> 1;
  seg[p << 1] += seg[p];
  seg[p << 1 | 1] += seg[p];
  aam[p << 1] += seg[p] * (m - l);
  aam[p << 1 | 1] += seg[p] * (r - m);
  seg[p] = 0;
}
void build_seg(int poi, int l, int r) {
  if (l + 1 == r) {
    aam[poi] = ain[l];
    return;
  }
  int m = l + r >> 1;
  build_seg(poi << 1, l, m);
  build_seg(poi << 1 | 1, m, r);
  aam[poi] = aam[poi << 1] + aam[poi << 1 | 1];
}
void update_seg(int ul, int ur, int poi, int l, int r, int val) {
  if (ul <= l && r <= ur) {
    aam[poi] += val * (r - l);
    seg[poi] += val;
    return;
  }
  push_seg(poi, l, r);
  int m = l + r >> 1;
  if (ul < m) update_seg(ul, ur, poi << 1, l, m, val);
  if (ur >= m + 1) update_seg(ul, ur, poi << 1 | 1, m, r, val);
  aam[poi] = aam[poi << 1] + aam[poi << 1 | 1];
}
long long query_seg(int ql, int qr, int poi, int l, int r) {
  if (ql <= l && r <= qr) return aam[poi];
  long long res = 0;
  int m = l + r >> 1;
  push_seg(poi, l, r);
  if (ql < m) res += query_seg(ql, qr, poi << 1, l, m);
  if (qr >= m + 1) res += query_seg(ql, qr, poi << 1 | 1, m, r);
  return res;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n = 0, m = 0;
  cin >> n >> m;
  for (auto i1 = ain.begin() + 1; i1 < ain.begin() + n + 1; i1++) cin >> *i1;
  build_seg(1, 1, n + 1);
  int inn, inx, iny, ink;
  for (auto i1 = 0; i1 < m; i1++) {
    cin >> inn >> inx >> iny;
    switch (inn) {
    case 1: {
      cin >> ink;
      update_seg(inx, iny + 1, 1, 1, n + 1, ink); 
      break; }
    case 2: {
      cout << query_seg(inx, iny + 1, 1, 1, n + 1) << endl;
      break; }
    }
  }
  return 0;
}