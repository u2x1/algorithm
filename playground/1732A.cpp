#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n);
    int g = 0;
    for(auto &x : v) { std::cin >> x; g = std::__gcd(g, x); }
    if (g == 1) { std::cout << 0; NL; continue; }
    if (n == 1) { std::cout << 1; NL; continue; }
    int mi = 0x3f3f3f3f;
    orep(i, 0, v.size()) {
      if (std::__gcd(g, i+1) == 1) {
        mi = std::min(mi, n-(i+1)+1);
      }
    }
    if (mi > 3) { mi = 3; }
    std::cout << mi; NL;
  }

  return 0;
}
