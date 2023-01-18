#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  while(t--) {
    double xa, ya, xb, yb, xc, yc; std::cin >> xa >> ya >> xb >> yb >> xc >> yc;
    double xac = xc - xa, yac = yc - ya;
    double xd, yd, xe, ye, xf, yf; std::cin >> xd >> yd >> xe >> ye >> xf >> yf;
    double xdf = xd - xf, ydf = yd - yf;
    bool bba = xac > 0, bbb = yac > 0;
    bool bbc = xdf > 0, bbd = ydf > 0;
    if (bba == bbc && bbd == bbb) {
      std::cout << "YES" << NL; continue;
    }
    if (bba == !bbc && bbb == !bbd) {
      std::cout << "YES" << NL; continue;
    }
    std::cout << "NO" << NL;
  }

  return 0;
}
