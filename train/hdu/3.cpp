#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using lnt = long long;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    lnt n, m, R, P; std::cin >> n >> m >> R >> P;
    // R = std::min(R, 6ll);
    std::vector<int> val(m);
    std::vector<int> tp(n);
    orep(i, 0, n) { std::cin >> tp[i]; tp[i]--; }
    orep(i, 0, m) { std::cin >> val[i]; }
    const lnt inf = -1e17;
    std::vector dp(n, std::vector(n, std::vector(m, std::vector(6, -inf))));
    orep(i, 0, n) { dp[i][i][tp[i]][0] = val[i]; }
    orep(lv, 0, R+1) {
      orep(i, 0, n) {
        orep(j, 0, n) {
          orep(k, i, j) {
            orep(ttp, 0, m) {
              if (dp[i][k][ttp][lv] == -inf || dp[i][k][ttp][lv] == -inf) { continue; }
              dp[i][j][ttp][lv+1] = std::max({
                  dp[i][j][ttp][lv]
                  , P * dp[i][k][ttp][lv]
                  });
              dp[i][j][ttp][lv+1] = std::max({
                  dp[i][j][ttp][lv]
                  , P * dp[i][k][ttp][lv]
                  });
            }
          }
        }
      }
    }
  }

  return 0;
}
