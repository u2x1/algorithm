#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    long long a, b; std::cin >> a >> b;
    if (a <= b*2ll) { std::cout << -1; NL; continue; }
    std::cout << b << " " << a-b; NL;
  }

  return 0;
}
