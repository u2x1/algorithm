#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k; std::cin >> n >> k;
    if (std::__lg(n)+1 > k) { n = (1 << k) - 1; }
    std::cout << n + 1; NL;
  }

  return 0;
}
