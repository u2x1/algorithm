#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; int k; std::cin >> s >> k;
//  s = " " + s;
  int n; std::cin >> n;
  std::vector<std::vector<int>> val(200, std::vector<int>(200, 0));
  // std::map<std::pair<int, int>, int> val; 
  orep(i, 0, n) {
    char l, r; int c; std::cin >> l >> r >> c;
    val[l][r] = c;
  }
  int inf = 0x3f3f3f3f;
  std::vector dp(105, std::vector(105, std::vector(30, -inf)));
  // std::function<int(int, int, int)> dfs = [&](int a, int b, char c) -> int {
  //   if (a <= 1) { return 0; }
  //   if (dp[a][b][c-'a'] != -inf) { return dp[a][b][c-'a']; }
  //   if (b == 0) { return (dp[a][b][c-'a'] = val[s[a-1]][c] + dfs(a-1, 0, s[a-1])); }
  //   int ret = -inf;
  //   orep(l, 'a', 'z'+1) {
  //     ret = std::max(ret, val[l][c] + dfs(a-1, b-(l!=s[a-1]), l));
  //   }
  //   return (dp[a][b][c-'a'] = ret);
  // };
  dp[0] = std::vector(105, std::vector(30, 0));
  orep(c, 'a', 'z') {
    if (c == s[0]) { continue; }
    dp[0][0][c-'a'] = -inf;
  }
  orep(i, 1ul, s.size()) {
    orep(j, 0, k+1) {
      orep(l, 'a', 'z'+1) {
        orep(r, 'a', 'z'+1) {
          if (r != s[i] && l != s[i-1] && j < 2) { continue; }
          if (l != s[i-1] && j < 1) { continue; }
          if (r != s[i] && j < 1) { continue; }
          dp[i][j][r-'a'] = std::max(dp[i][j][r-'a'], dp[i-1][j-(r!=s[i])][l-'a']+val[l][r]);
        }
      }
    }
  }
  // int ret = -0x3f3f3f3f;
  // orep(c, 'a', 'z'+1) {
  //   ret = std::max(ret, val[{s[s.size()-2], c}] + dfs(s.size()-2, k-(c!=s.back()), s[s.size()-2]));
  // }
  // s += "~";
  // std::cout << dfs(s.size()-1, k, '~');
  // orep(i, 0, 6) {
  //   orep(j, 0, k+1) {
  //     orep(c, 'a', 'z'+1) {
  //       std::cout << i << " " << j << " " << c << ": " << dp[i][j][c-'a']; NL;
  //     }
  //   }
  // } NL;
  int ret = -inf;
  orep(i, 0, k+1) {
    orep(c, 0, 26) {
      ret = std::max(ret, dp[s.size()-1][i][c]);
    }
  }
  std::cout << ret;

  // std::cout << s.size()-1 << " " << k << " " << s.back(); NL;
  

  return 0;
}
