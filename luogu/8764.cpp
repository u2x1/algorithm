#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::vector dp(100, std::vector(60, std::vector(2, -1ll)));
  auto solve = [&,
    f = [&](auto &&f, std::string s, int i, int cnt, bool lim) {
      if (i == -1) { return 1ll * (cnt == 0); }
      if (dp[i][cnt][lim] != -1) { return dp[i][cnt][lim]; }
      long long ret = 0;
      orep(x, 0, 2) {
        if (lim && s[i] - '0' < x) { break; }
        if (cnt == 0 && x == 1) { break; }
        ret += f(f, s, i-1, (cnt-x), (lim && s[i]-'0' == x));
      }
      return dp[i][cnt][lim] = ret;
    }
  ] (long long x, int k) {
    dp = std::vector(100, std::vector(60, std::vector(2, -1ll)));
    std::string s;
    while(x) { s += (x & 1) + '0'; x /= 2; }
    return f(f, s, s.size()-1, k, 1);
  };
  long long a, k; std::cin >> a >> k;
  std::cout << solve(a, k) - solve(1, k);

  return 0;
}
