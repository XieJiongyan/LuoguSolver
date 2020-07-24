#include <iostream>
#include <algorithm>
#include <vector>
using namespace::std;

struct nod {
  int ipa;
  int ldi;
  int ian;
};
vector<nod> vpnx{};

int ffan(int ithn) {
  auto& sthn(vpnx[ithn]);
  auto& itha(sthn.ian);
  if (itha == ithn) return ithn;
  int ilsn(itha);
  itha = ffan(itha);
  sthn.ldi += vpnx[ilsn].ldi;
  return itha;
}
signed main() {
  long lape{};
  int lmid = 0x3f3f3f3f;
  cin >> lape;
  vpnx.resize(lape);
  for (auto& i1 : vpnx)
    i1.ian = &i1 - &vpnx[0];
  for (auto& i1 : vpnx) {
    cin >> i1.ipa;
    i1.ipa--;
    auto& sthp = vpnx[i1.ipa];
    i1.ian = ffan(&sthp - &vpnx[0]);
    if (ffan(sthp.ian) == &i1 - &*vpnx.begin()) lmid = min(lmid, sthp.ldi + 1);
    else i1.ldi = sthp.ldi + 1;
  }
  cout << lmid << endl;
  return 0;
}