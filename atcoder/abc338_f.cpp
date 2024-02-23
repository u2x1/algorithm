#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  int m; std::cin >> m;
  std::vector dis(n, std::vector(n, inf));
  for (int i = 0; i < m; ++i) {
    int a, b, c; std::cin >> a >> b >> c; --a, --b;
    dis[a][b] = std::min(dis[a][b], c);
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        // if (dis[i][k] == inf || dis[k][j] == inf) { continue; }
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  std::vector dp(1 << n, std::vector(n, inf));
  for (int i = 0; i < n; ++i) { dp[1 << i][i] = 0; }
  for (int s = 0; s < (1 << n); ++s) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!((s >> i) & 1) || ((s >> j) & 1)) { continue; }
        if (dp[s][i] == inf || dis[i][j] == inf) { continue; }
        dp[s | (1 << j)][j] = std::min(dp[s | (1 << j)][j], dp[s][i] + dis[i][j]);
      }
    }
  }
  int ret = inf;
  for (int i = 0; i < n; ++i) {
    ret = std::min(ret, dp[(1<<n)-1][i]);
  }
  if (ret == inf) { std::cout << "No"; }
  else { std::cout << ret; }

  return 0;
}
