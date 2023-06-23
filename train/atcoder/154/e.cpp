#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  int k; std::cin >> k;
  std::vector dp(2, std::vector(s.size()+1, std::vector(k+1, 0)));
  dp[0][s.size()][0] = dp[1][s.size()][0] = 1;
  orep(ti, 0, 2) {
    for(int i = s.size()-1; i > -1; --i) {
      orep(j, 0, k+1) {
        if (!ti) {
          orep(d, 0, 10) {
            if (j-(d!=0) == -1) { break; }
            dp[0][i][j] += dp[0][i+1][j-(d!=0)];
          }
        } else {
          orep(d, 0, s[i]-'0'+1) {
            if (j-(d!=0) == -1) { break; }
            dp[1][i][j] += dp[d==(s[i]-'0')][i+1][j-(d!=0)];
          }
        }
        // std::cout << ti << " " << i << " " << j << ": " << dp[ti][i][j]; NL;
      }
    }
  }
  std::cout << dp[1][0][k];

  return 0;
}
