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
    int n; std::cin >> n;
    std::vector<std::pair<int, int>> segs;
    orep(i, 0, n) {
      int a, b; std::cin >> a >> b;
      segs.emplace_back(a, b);
    }
    std::sort(all(segs), [](auto x, auto y) { return x.second < y.second; });
    int ret = 0;
    std::vector<int> dp(n+1);
    orep(i, 0, n) {
      dp[i+1] = dp[i];
      orep(j, 0, i) {
        auto [l2, r2] = segs[i];
        auto [l1, r1] = segs[j];
        if (r1 >= l2) {
          int pre = std::upper_bound(all(segs), std::min(l1, l2)-1, [](auto val, auto x) { return val < x.second; })- segs.begin();
          dp[i+1] = std::max(dp[i+1], dp[pre] + 2);
          ret = std::max(ret, dp[i+1]);
        }
      }
    }
    std::cout << n-ret; NL;
  }

  return 0;
}

