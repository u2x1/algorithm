#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    std::vector<std::pair<int, int>> seg(n);
    std::sort(all(seg), [](auto x, auto y) { return x.second < y.second; });
    auto tp = seg[0];
    int ret = 0;
    orep(i, 1, n) {
      auto x = seg[i];
      if (tp.second < x.first) { 
    }
  }

  return 0;
}
