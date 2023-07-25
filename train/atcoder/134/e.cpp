#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  const int inf = 0x3f3f3f3f;
  std::vector<int> v(n), dp(n+1, inf);
  for(auto &x : v) { std::cin >> x; x = -x; }
  for(auto x : v) {
    *(std::upper_bound(all(dp), x)) = x;
  }
  orep(i, 0, n+1) {
    if (dp[i] == inf) { std::cout << i; exit(0); }
  }

  return 0;
}
