#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::vector<int>> son(n+1);
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b;
    son[a].emplace_back(b);
    son[b].emplace_back(a);
  }
  std::vector<long long> sum(n+1), dp(n+1);
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    sum[u] = 1;
    for(auto x : son[u]) { 
      if (x == fa) { continue; }
      dfs(x, u);
      sum[u] += sum[x];
      dp[u] += dp[x] + sum[x];
    }
  };
  dfs(1, 0);
  std::function<void(int, int)> dfs2 = [&](int u, int fa) {
    if (fa) { dp[u] += dp[fa] - (dp[u]+sum[u]) + (n-sum[u]); }
    for(auto x : son[u]) {
      if (x == fa) { continue; }
      dfs2(x, u);
    }
  };
  dfs2(1, 0);
  orep(i, 1, n+1) { std::cout << dp[i]; NL; }

  return 0;
}
