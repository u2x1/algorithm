#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 1 << 30;
const lnt linf = 1ll << 62;

#define upd(a,b) a = (a > b) ? a : b

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    std::vector<std::array<int, 3>> v(n);

    for (auto &[a, b, c] : v) {
      std::cin >> a >> b >> c;
    }

    const int N = std::min(n+1, 205);
    std::vector dp(N, std::vector(N, std::vector(N, 0)));
    auto ndp = dp;

    dp[1][0][0] = v[0][0];
    dp[0][1][0] = v[0][1];
    dp[0][0][1] = v[0][2];

    for (int i = 1; i < n; ++i) {

      for (int a = 0; a <= i && a < N-1; ++a) {
        for (int b = 0; b <= i && b < N-1; ++b) {
          ndp[1][a][b] = 0;
          ndp[a][1][b] = 0;
          ndp[a][b][1] = 0;
        }
      }

      for (int a = 0; a <= i && a < N-1; ++a) {
        for (int b = 0; b <= i && b < N-1; ++b) {
          const int na = a + !!a, nb = b + !!b;
          const int ca = na - (!!na), cb = nb - (!!nb);

          upd(ndp[1][na][nb], dp[1][a][b] + v[i][0] - ca - cb);
          upd(ndp[2][1][nb],  dp[1][a][b] + v[i][1] - 1 - cb);
          upd(ndp[2][na][1],  dp[1][a][b] + v[i][2] - ca - 1);

          upd(ndp[na][1][nb], dp[a][1][b] + v[i][1] - ca - cb);
          upd(ndp[1][2][nb],  dp[a][1][b] + v[i][0] - 1 - cb);
          upd(ndp[na][2][1],  dp[a][1][b] + v[i][2] - ca - 1);

          upd(ndp[na][nb][1], dp[a][b][1] + v[i][2] - ca - cb);
          upd(ndp[1][nb][2],  dp[a][b][1] + v[i][0] - 1 - cb);
          upd(ndp[na][1][2],  dp[a][b][1] + v[i][1] - ca - 1);
        }
      }

      std::swap(dp, ndp);
    }

    int ret = 0;
    for (auto &a : dp) {
      for (auto &b : a) {
        for (auto c : b) {
          ret = std::max(ret, c);
        }
      }
    }

    std::cout << ret; NL;
  }

  return 0;
}

