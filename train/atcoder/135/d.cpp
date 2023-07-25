#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  std::vector<std::vector<int>> dp(s.size()+2, std::vector<int>(20, 0));
  const int mod = 1e9+7;
  s = "0" + s;
  dp[0][0] = 1;
  orep(i, 0ul, s.size()) {
    orep(j, 0, 10) {
      orep(k, 0, 14) {
        if (s[i] != '?' && s[i] - '0' != j) { continue; }
        dp[i+1][(k*10+j)%13] += dp[i][k];
        dp[i+1][(k*10+j)%13] %= mod;
      }
    }
  }
  std::cout << dp[s.size()][5];

  return 0;
}
