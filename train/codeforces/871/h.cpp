#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  const int mod = 1e9+7;
  while(t--) {
    int n, k; std::cin >> n >> k;
    std::vector<long long> dp(64);
    orep(i, 0, n) {
      int x; std::cin >> x;
      std::vector<long long> dp2 = dp;
      orep(i, 0, 64) {
        if (!dp[i]) { continue; }
        dp2[x&i] += dp[i];
        dp2[x&i] %= mod;
      }
      dp2[x]++; dp2[x] %= mod;
      dp = dp2;
    }
    long long ret = 0;
    for(int i = 0; i < 64; ++i) {
      if (__builtin_popcount(i) != k) { continue; }
      ret += dp[i];
      ret %= mod;
    }
    std::cout << ret; NL;
  }

  return 0;
}
