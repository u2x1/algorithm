#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    long long k; std::cin >> k;
    k *= 2;
    bool f = 0;
    for(long long n = 6; n <= k; ++n) {
      if (k % n == 0 && (k/n+1-n) % 2 == 0) { std::cout << n; NL; f = 1; break; }
    }
    if (!f) { std::cout << -1; NL; }
  }

  return 0;
}
