#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n);
    for(auto &x : v) { std::cin >> x; }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    int l = -1, r = 1e9+1;
    auto check = [&](int limit) {
      int block = 1;
      int L = 0;
      orep(i, 0, n) {
        int center = (v[i] + v[L]) / 2;
        if (center - v[L] > limit || v[i] - center > limit) { ++block; L = i; }
      }
      return (block <= 3);
    };
    while(l < r-1) {
      int m = l + ((r-l) >> 1);
      if (check(m)) { r = m; }
      else { l = m; }
    }
    std::cout << r; NL;
  }

  return 0;
}
