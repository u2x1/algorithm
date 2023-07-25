#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, shit; std::cin >> n >> shit;
    std::vector<std::vector<int>> v(3, std::vector<int>(n));
    for(auto &x : v) {
      for(auto &y : x) {
        std::cin >> y;
      }
      std::reverse(all(x));
    }
    int cur = 0;
    while(1) {
      bool flag = 0;
      orep(i, 0, 3) {
        if (v[i].empty() || (v[i].back() & ~shit)) { continue; }
        flag = 1;
        cur |= v[i].back();
        v[i].pop_back();
      }
      if (!flag) { break; }
    }
    std::cout << (cur == shit ? "Yes" : "No"); NL;
  }
  return 0;
}
