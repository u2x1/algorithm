#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::string s;
  std::vector mp(n+2, std::vector(m+2, 0));
  const int inf = 1<<30;
  std::vector dp(n+2, std::vector(m+2, std::array<int, 2>{inf, inf}));
  orep(i, 0, n) {
    std::cin >> s;
    orep(j, 0, m) { mp[i+1][j+1] = s[j]-'0'; }
  }
  dp[1][1][mp[1][1]] = 0;
  std::vector<std::array<int, 3>> q {{1, 1, mp[1][1]}};
  auto upd = [&](int x, int y, int v ,int t) {
    if (x > n || y > m || x <= 0 || y <= 0) { return; }
    if (dp[x][y][v] > t) { dp[x][y][v] = t + (mp[x][y] != v); q.push_back({x, y, v}); }
  };
  for(int i = 0; i < q.size(); ++i) {
    auto [x, y, v] = q[i];
    auto t = dp[x][y][v] + 1;
    // std::cout << x << " " << y << " " << v << " " << t << std::endl;
    upd(x+1, y, !v, t); upd(x, y+1, !v, t);
    upd(x-1, y, !v, t); upd(x, y-1, !v, t);
  }
  std::cout << std::min(dp[n][m][0], dp[n][m][1]);

  return 0;
}
