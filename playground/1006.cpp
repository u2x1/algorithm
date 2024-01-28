#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cout << std::setprecision(9) << std::fixed;
  int t; std::cin >> t;
  while(t--) {
    long double n; std::cin >> n;
    std::cout << ((n-1)*2 + (n-2)*(n-1)*2) / (n*(n-1)) << " " << (n==2 ? "1.000000000" : "2.000000000"); NL;
  }

  return 0;
}
