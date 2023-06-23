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
    int n; std::cin >> n;
    auto son = std::vector<std::vector<int>>(n+1, std::vector<int>());
    std::vector<long long> c = std::vector<long long>(n+1);
    orep(_, 1, n) {
      int a, b; std::cin >> a >> b;
      son[a].emplace_back(b);
      son[b].emplace_back(a);
    }
    std::function<int(int, int)> dfs = [&](int u, int fa) {
      if (son[u].size() == 1 && son[u][0] == fa) { return (c[u] = 1); }
      for(int v : son[u]) {
        if (v == fa) { continue; }
        c[u] += dfs(v, u);
      }
      return c[u];
    };
    dfs(1, 0);
    int q; std::cin >> q;
    while(q--) {
      int a, b; std::cin >> a >> b;
      std::cout << c[a] * c[b]; NL;
    }
  }

  return 0;
}
