#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

long long a, b, ainb, bina, ainbmax, ainbmin = 1ll << 62, binamax, binamin = 1ll << 62;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;

  auto mswap = [&]() {
    std::swap(a, b); std::swap(ainb, bina);
    std::swap(ainbmax, binamax);
    std::swap(ainbmin, binamin);
  };

  while(n--) {
    long long x, y, z; std::cin >> x >> y >> z;

    if (z == 1) { std::swap(x, y); mswap(); }
      a += x; ainb += y;
      ainbmax = std::max(ainbmax, y);
      ainbmin = std::min(ainbmin, y);
    if (z == 1) { std::swap(x, y); mswap(); }

    int s = 0;
    auto check = [&]() {
      if (ainb > b) {
        if (ainb - ainbmin <= b) { s = std::max(s, 1); }
        else if (ainb - ainbmax <= b) { s = std::max(s, 2); }
        else { s = std::max(s, 3); }
      }
      mswap();
    };
    check();
    check();
    switch(s) { 
      case 0: std::cout << "EF"; break;
      case 1: std::cout << "EFX"; break;
      case 2: std::cout << "EF1"; break;
      case 3: std::cout << "E"; break;
    } NL;
  }

  return 0;
}
