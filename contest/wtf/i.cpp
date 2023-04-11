#include <iostream>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long forestH, forestW, blockH, blockW;
  std::cin >> forestH >> forestW >> blockH >> blockW;
  long long ret = (forestH/blockH) * (forestW/blockW);

  const long long recH = forestH/blockH*blockH, recW = forestW/blockW*blockW;
  const int hascorner = (forestH%blockH) + (forestW%blockW);
  int left = 0;
  if (forestH > recH) {
    const int brk = blockH/(forestH-recH);
    const int add = ceil(1.0*recW/(brk*blockW));
    if (brk*add*(forestH-recH)*blockW > (forestH-recH)*recW) { left++; }
    ret += add;
  }
  if (forestW > recW) {
    const int brk = blockW/(forestW-recW);
    const int add = ceil(1.0*recH/(brk*blockH));
    if (brk*add*(forestW-recW)*blockH > (forestW-recW)*recH) { left++; }
    ret += add;
  }
  if (hascorner) {
    if (!left) { ++ret; }
  }
  std::cout << ret;
  return 0;
}
