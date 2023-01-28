#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  std::cout << std::setprecision(10);
  while(t--){
    double sx, sy, tx, ty; std::cin >> sx >> sy >> tx >> ty;
    if (tx <= sx && ty <= sy) {
      double w = std::max(tx, sx-tx)
           , h = std::max(ty, sy-ty);
      std::cout << w*h / (sx*sy);
    } else if (tx >= sx && ty <= sy) {
      double h = std::max(ty, sy-ty);
      std::cout << (sx*h) / (sx*sy+(tx-sx)*h);
    } else if (tx <= sx && ty >= sy) {
      double w = std::max(tx, sx-tx);
      std::cout << (sy*w) / (sx*sy+(ty-sy)*w);
    } else {
      std::cout << sx*sy / (tx*ty);
    }
    std::cout << NL;
  }
  return 0;
}
