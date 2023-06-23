#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> v(m+1);
  orep(i, 1, n+1) {
    int tmp; std::cin >> tmp; tmp+=i;
    if (tmp >= 0) { v[0].push_back({tmp, i}); }
    else {
      int r = ((tmp%i+i)%i-tmp)/i;
      if (r < m) { v[r].push_back({(tmp%i+i)%i, i}); }
    }
  }
  orep(i, 0, m) {
    std::sort(v[i].begin(), v[i].end());
    int ret = 0;
    for(auto &[x, d] : v[i]) {
      // std::cout << x << " ";
      if (x == ret) {
        ++ret;
      }
      if (x+d < n) {
        v[i+1].push_back({x+d, d});
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}
