#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::string s, l, r;
    int m; std::cin >> s >> m >> l >> r;
    std::vector dp(s.size()+1, std::vector<int>(10, -1));
    orep(i, 1ul, s.size()) {
      dp[i] = dp[i-1];
      dp[i][s[i-1]-'0'] = i-1;
    }
    dp[s.size()] = dp[s.size()-1];
    dp[s.size()][s.back()-'0'] = s.size()-1;
    std::function<bool(int, int)> dfs = [&](int p, int x) {
      if (p == -1) { return true; }
      bool ret = 0;
      orep(a, l[p]-'0', r[p]-'0'+1) {
        orep(j, 0, 10) {
          if (a == j) { continue; }
          if (dp[x][j] == -1) { continue; }
          ret |= dfs(p-1, dp[x][j]);
        }
      }
      return ret;
    };
    std::cout << (dfs(m-1, s.size()) ? "YES" : "NO"); NL;
  }


  return 0;
}
