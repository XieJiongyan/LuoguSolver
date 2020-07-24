#include <iostream>
#include <array>

#define int long long

using namespace::std;

constexpr int karz{ 100005 };
int lp{ 0 };

array<int, karz> ain{};
array<int, karz << 2> segp{};
array<int, karz << 2> segm{};
array<int, karz << 2> aam{};

void build(int poi, int l, int r) {
  segm[poi] = 1;
  if (l + 1 == r) {
    aam[poi] = ain[l];
    return;
  }
  int m{ l + r >> 1 };
  build(poi << 1, l, m), build(poi << 1 | 1, m, r);
  aam[poi] = (aam[poi << 1] + aam[poi << 1 | 1]) % lp;
}
void push_down(int poi, int l, int r) {
  int m{ l + r >> 1 };
  segm[poi << 1] = (segm[poi] * segm[poi << 1]) % lp, segm[poi << 1 | 1] = (segm[poi << 1 | 1] * segm[poi]) % lp;
  segp[poi << 1] = ((segp[poi << 1] * segm[poi]) % lp + segp[poi]) % lp, segp[poi << 1 | 1] = ((segp[poi << 1 | 1] * segm[poi]) % lp + segp[poi]) % lp;
  aam[poi << 1] = ((aam[poi << 1] * segm[poi]) % lp + (segp[poi] * (m - l)) % lp) % lp, aam[poi << 1 | 1] = ((aam[poi << 1 | 1] * segm[poi]) % lp + (segp[poi] * (r - m)) % lp) % lp;
  segm[poi] = 1, segp[poi] = 0;
}
void modify(int ml, int mr, int poi, int l, int r, int mul, int plu) {
  if (ml <= l && r <= mr) {
    segm[poi] *= mul, segp[poi] = (segp[poi] * mul) % lp + plu;
    aam[poi] = (aam[poi] * mul) % lp + (plu * (r - l)) % lp;
    segm[poi] %= lp, segp[poi] %= lp, aam[poi] %= lp;
    return;
  }
  push_down(poi, l, r);
  int m{ l + r >> 1 };
  if (ml < m) modify(ml, mr, poi << 1, l, m, mul, plu);
  if (m + 1 <= mr) modify(ml, mr, poi << 1 | 1, m, r, mul, plu);
  aam[poi] = (aam[poi << 1] + aam[poi << 1 | 1]) % lp;
}
int query_seg(int ql, int qr, int poi, int l, int r) {
  if (ql <= l && r <= qr) return aam[poi];
  push_down(poi, l, r);
  int rev{ 0 };
  int m{ l + r >> 1 };
  if (ql < m) rev = query_seg(ql, qr, poi << 1, l, m) + rev;
  if (m + 1 <= qr) rev = (query_seg(ql, qr, poi << 1 | 1, m, r) + rev) % lp;
  return rev;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int ln{}, lm{};
  cin >> ln >> lp;
  for (auto i1 = 1; i1 < ln + 1; i1++) {
    cin >> ain[i1];
    ain[i1] %= lp;
  }
  build(1, 1, ln + 1);
  cin >> lm;
  int in1{}, in2{}, in3{}, in4{};
  for (auto i1 = 0; i1 < lm; i1++) {
    cin >> in1 >> in2 >> in3;
    switch (in1) {
    case 1: {
      cin >> in4;
      in4 %= lp;
      modify(in2, in3 + 1, 1, 1, ln + 1, in4, 0);
      break; }
    case 2: {
      cin >> in4;
      in4 %= lp;
      modify(in2, in3 + 1, 1, 1, ln + 1, 1, in4);
      break; }
    case 3: {
      cout << query_seg(in2, in3 + 1, 1, 1, ln + 1) << endl;
      break; }
    }
  }
  return 0;
}