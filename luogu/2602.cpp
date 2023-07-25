#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  using ll = long long;

  std::vector dp = std::vector(20, std::vector(20, std::vector(2, std::vector(2, 0ll))));
  auto solve = [&,
    dfs = [&](std::string s, int i, int d, ll cnt, bool lim, bool zero, auto &&f) {
      ll ret = 0;
      if (i == -1) { return cnt; }
      if (dp[i][cnt][lim][zero]) { return (dp[i][cnt][lim][zero]); }
      orep(x, 0, 10) {
        if (lim && s[i]-'0' < x) { break; }
        ret += f(s, i-1, d, cnt+(((!zero)||x)&&(x==d)), lim&&(s[i]-'0'==x), (zero && !x), f);
      }
      return dp[i][cnt][lim][zero] = ret;
    }
  ]
  (ll x, int d){
    std::string s = std::to_string(x); std::reverse(all(s));
    dp = std::vector(20, std::vector(20, std::vector(2, std::vector(2, 0ll))));
    return dfs(s, s.size()-1, d, 0ll, true, true, dfs);
  };

  ll a, b; std::cin >> a >> b;
  orep(i, 0, 10) {
    std::cout << solve(b, i)-solve(a-1, i) << " ";
  }

  return 0;
}
