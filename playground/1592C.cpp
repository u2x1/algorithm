#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k; std::cin >> n >> k;
    std::vector<int> v(n+1);
    int s = 0;
    orep(i, 1, n+1) { std::cin >> v[i]; s ^= v[i]; }
    std::vector<std::vector<int>> son(n+1);
    orep(i, 1, n) {
      int a, b; std::cin >> a >> b;
      son[a].emplace_back(b);
      son[b].emplace_back(a);
    }
    if (s == 0) { std::cout << "YES"; NL; continue; }
    int cnt = 0;
    std::function<int(int, int)> dfs = [&](int u, int fa) {
      int ret = v[u];
      for(auto vv : son[u]) {
        if (fa == vv) { continue; }
        ret ^= dfs(vv, u);
      }
      if (ret == s) { ++cnt; ret = 0; }
      return ret;
    };
    dfs(1, 0);
    if (cnt >= 2 && k > 2) { std::cout << "YES"; NL; }
    else { std::cout << "NO"; NL; }
  }

  return 0;
}
