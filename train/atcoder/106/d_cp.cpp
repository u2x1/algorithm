#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, q; std::cin >> n >> m >> q;
  std::vector dp(n+5, std::vector<int>(n+5, 0));
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    dp[a][b]++;
  }
  for(int k = 1; k <= n; ++k) {
    for(int i = 1; i <= n && i+k <= n; ++i) {
      dp[i][i+k] += dp[i+1][i+k] + dp[i][i+k-1] - dp[i+1][i+k-1];
    }
  }

  orep(i, 0, q) {
    int a, b; std::cin >> a >> b;
    std::cout << dp[a][b]; NL;
  }

  return 0;
}
