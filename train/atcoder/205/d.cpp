#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
long long a[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  orep(i, 0, n) { std::cin >> a[i]; }
  std::sort(a, a+n);
  while(q--) {
    long long k; std::cin >> k;
    long long l = 0, r = 1ll << 62;
    // long long l = 0, r = 1ll << 5;
    while(l < r-1) {
      long long x = l + ((r-l)>>1);
      // std::cout << x << "---"; NL;
      long long i = (std::upper_bound(a, a+n, x) - a);
      // std::cout << x-i << " for " << x; NL;
      if (x-i < k) { l = x; }
      else { r = x; }
    }
    std::cout << r; NL;
  }

  return 0;
}
