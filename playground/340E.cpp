#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  int cnt = n;
  std::vector<int> f(n+1), g(n+1);
  orep(i, 1, n+1) {
    int x; std::cin >> x;
    if (x == -1) { continue; }
    f[x] = 1; g[i] = 1;
    --cnt;
  }
  int k = 0;
  orep(i, 1, n+1) {
    if (f[i]) { continue; }
    if (g[i]) { ++k; }
  }
  std::vector<std::vector<long long>> dp(2*n+1, std::vector<long long>(2*n+1));
  dp[0][0] = 1;
  const int mod = 1000000007;
  orep(i, 1, 2*n+1) {
    dp[i][0] = dp[i-1][0] * i % mod;
    dp[i][1] = dp[i][0] * i % mod;
  }
  std::function<int(int, int)> dfs = [&](int x, int y) {
    if (y <= 1) { return dp[x][y]; }
    if (dp[x][y]) { return dp[x][y]; }
    return dp[x][y] = (1ll*dfs(x, y-1)*x%mod + 1ll*dfs(x+1, y-2)*(y-1)%mod)%mod;
  };
  std::cout << dfs(k, cnt-k);

  return 0;
}
