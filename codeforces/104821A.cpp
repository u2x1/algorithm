#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    int n, m; std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> mp[i];
    }
    std::vector dp(n, std::vector(m, std::vector(n, std::vector<char>(m, -1))));
    auto dfs = [&](auto &&self, int a, int b, int c, int d) -> char {
      if (a < 0 || a >= n || b < 0 || b >= m || (mp[a][b] == 'O')) {
        return 0;
      }
      if (c < 0 || c >= n || d < 0 || d >= m || (mp[c][d] == 'O')) {
        return 1;
      }
      if (a == c && b == d) { return 0; }
      if (~dp[a][b][c][d]) { return dp[a][b][c][d]; }
      dp[a][b][c][d] = 0;
      dp[a][b][c][d] = self(self, a + 1, b, c + 1, d)
                    || self(self, a, b + 1, c, d + 1)
                    || self(self, a - 1, b, c - 1, d)
                    || self(self, a, b - 1, c, d - 1);
      return dp[a][b][c][d];
    };
    int ret = 0;
    std::vector ok(n, std::vector<char>(m, 0));
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < m; ++b) {
        int cnt = n * m;
        if (mp[a][b] == 'O') { continue; }
        for (int c = 0; c < n; ++c) {
          for (int d = 0; d < m; ++d) {
            cnt -= dfs(dfs, a, b, c, d);
          }
        }
        ok[a][b] = (cnt == 1);
      }
    }
    std::vector vis(n, std::vector<char>(m, 0));
    auto dfs2 = [&](auto &&self, int x, int y) -> void {
      if (x < 0 || x == n || y < 0 || y == m) { return; }
      if (vis[x][y]) { return; }
      if (mp[x][y] == 'O') { return; }
      vis[x][y] = 1;
      ok[x][y] = 1;
      self(self, x-1, y);
      self(self, x, y-1);
      self(self, x, y+1);
      self(self, x+1, y);
    };
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!ok[i][j]) { continue; }
        dfs2(dfs2, i, j);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ret += ok[i][j];
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}
