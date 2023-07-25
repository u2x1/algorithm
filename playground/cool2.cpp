#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, m; std::cin >> n >> m; ++m;
  std::vector<long long> v { 1 };
  orep(i, 1, m) { v.emplace_back(v.back()*2); }
  const int mod = 1e9+7;
  std::vector<long long> dp(n+1);
  dp[0] = 1;
  for(auto x : v) {
    auto dp2 = dp;
    for(int i = x; i <= n; ++i) {
      dp2[i] += dp2[i-x];
      dp2[i] %= mod;
    }
    dp = dp2;
  }
  std::cout << dp[n];

  return 0;
}
