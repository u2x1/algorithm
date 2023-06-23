#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> v1(n), rk(n+5);
  for(auto &x : v1) { std::cin >> x; }
  orep(i, 0, n) {
    int x; std::cin >> x; rk[x] = i;
  }
  const int inf = 0x3f3f3f3f;
  std::vector<int> dp(n+5, inf);
  orep(i, 0, n) {
    int x = rk[v1[i]];
    *std::lower_bound(all(dp), x) = x;
  }
  int cnt = 0;
  for(auto x : dp) { if(x != inf) { ++cnt; } }
  std::cout << n-cnt;

  return 0;
}
