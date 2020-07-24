#include <iostream>
#include <algorithm>

using namespace::std;

constexpr int kmsz = 200000;
constexpr int kmh = 20;

long long mst[kmsz][kmh]{};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  long long lm = 0, ld = 0;
  cin >> lm >> ld;
  char inc = ' ';
  long long inn = 0;
  long long lmsz = -1, llas = 0;
  for (auto i1 = 0; i1 < lm; i1++) {
    cin >> inc >> inn;
    switch (inc) {
    case 'Q': {
      long long lhp = -1;
      while ( 1ll << (++lhp + 1) <= inn) continue;
      long long lans = max(mst[lmsz][lhp], mst[lmsz - inn + (1 << lhp)][lhp]);
      llas = lans;
      cout << lans << endl; 
      break; }
    case 'A': {
      inn = (inn + llas) % ld;
      mst[++lmsz][0] = inn;
      for (auto i2 = 1; (1 << i2) <= lmsz + 1; i2++) 
        mst[lmsz][i2] = max(mst[lmsz][i2 - 1], mst[lmsz - (1 << i2 - 1)][i2 - 1]); 
      break; }
    }
  }
  return 0;
}