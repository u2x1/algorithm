#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::vector<int> primes, vis(1e6+5);
  vis[1] = 1;
  orep(i, 2, 1e6+1) {
    if (!vis[i]) { primes.emplace_back(i); }
    for(auto x : primes) {
      if (i*x > 1e6) { break; }
      vis[i*x] = 1;
      if (i % x == 0) { break; }
    }
  }
  int t; std::cin >> t;
  while(t--) {
    int x; std::cin >> x;
    bool flag = 1;
    while(x) {
      if (vis[x]) { flag = 0; break; }
      x /= 10;
    }
    std::cout << (flag ? "YES": "NO");NL;
  }

  return 0;
}
