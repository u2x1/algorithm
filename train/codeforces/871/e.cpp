#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    std::vector mp(n+2, std::vector(m+2, 0));
    orep(i, 1, n+1) {
      orep(j, 1, m+1) {
        std::cin >> mp[i][j];
      }
    }
    std::function<long long(int, int)> dfs = [&](int x, int y)  {
      if (mp[x][y] == 0) { return 0ll; }
      int c = mp[x][y];
      mp[x][y] = 0;
      return c
        + dfs(x+1, y) + dfs(x-1, y)
        + dfs(x, y+1) + dfs(x, y-1);
    };
    long long ret = 0;
    orep(i, 1, n+1) {
      orep(j, 1, m+1) {
        ret = std::max(ret, dfs(i, j));
      }
    }
    std::cout << ret; NL;
 }

  return 0;
}
