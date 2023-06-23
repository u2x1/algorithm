#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n);
    for(auto &x : v) { std::cin >> x; }
    auto __lcm = [](const long long x, const long long y) { return x*y/std::__gcd(x,y); };
    auto lcm = [&](const int l, const int r) {
      if (l == r-1) { return 1ll*v[l]; }
      long long ret = 1;
      orep(i, l, r) {
        ret = __lcm(v[i], ret);
      }
      return ret;
    };
    // std::cout << lcm(0, 1); NL;
    orep(x, 1, 100) { 
      bool ok = 1;
      orep(i, 0, n) {
        orep(j, i+1, n+1) {
          // if (!ok) { break; }
          if (x == lcm(i, j)) { std::cout << "for " << x << " = [" << i << "," << j << ")"; NL; ok = 0; continue; }
        }
      }
      if (ok) {
        std::cout << x << " IS OK "; NL; break;
      }
    }
NL; NL; NL;
    // break;
  }

  return 0;
}
