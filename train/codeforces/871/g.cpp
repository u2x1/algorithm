#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  const int maxN = 1500;
  std::vector val(maxN, std::vector(maxN, 0ll));
  std::vector sum(maxN, std::vector(maxN, 0ll));
  std::vector dp(maxN, std::vector(maxN, 0ll));
  std::vector ret(1e6+5, 0ll);
  {
    long long cur = 1;
    orep(i, 1, maxN) {
      orep(j, 1, i+1) {
        if (cur == (int)1e6+5) { break; }
        val[i][j] = cur*cur;
        sum[i][j] = val[i][j] + sum[i-1][j];
        dp[i][j] = sum[i][j] + dp[i-1][j-1];
        ret[cur] = dp[i][j];
        cur++;
      }
    }
  }
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::cout << ret[n]; NL;
  }

  return 0;
}
