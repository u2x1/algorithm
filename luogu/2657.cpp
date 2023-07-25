#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);

  // std::vector dp(10, std::vector(10, std::vector(2, std::vector(2, 0ll))));
  std::vector dp(10, std::vector(10, 0ll));
  auto solve = [&,
    f = [&](auto &&f, std::string s, int i, int last, bool lim, bool zero) {
      if (i == -1) { return 1ll; }
      if (dp[i][last]) { return dp[i][last]; }
      long long ret = 0;
      orep(x, 0, 10) {
        if (lim && s[i] - '0' < x) { break; }
        if (!zero && abs(x-last) < 2) { continue; }
        ret += f(f, s, i-1, x, (lim && s[i]-'0' == x), ((zero && !x)));
        // std::cout << "f " << i << " got +" << f(f, s, i-1, x, (lim && s[i]-'0' == x), (zero && !x))  << " from " << x; NL;
      }
      return dp[i][last] = ret;
    }
  ]
  (int x) {
    dp = std::vector(10, std::vector(10, 0ll));
    std::string s = std::to_string(x);
    std::reverse(all(s));
    return f(f, s, s.size()-1, 0, 1, 1);
  };

  int a, b; std::cin >> a >> b;
  std::cout << solve(b) - solve(a-1);

  return 0;
}
