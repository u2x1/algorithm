#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m, k, H; std::cin >> n >> m >> k >> H;
    std::vector<int> v(n); for(auto &x : v) { std::cin >> x; }
    int ret = 0;
    for(auto x : v) {
      if (x != H && abs(x-H) % k == 0 && abs(x-H) / k < m) { ++ret; }
    }
    std::cout << ret; NL;
  }


  return 0;
}
