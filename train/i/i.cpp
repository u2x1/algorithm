#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<int> v(n);
  for(auto &x : v) { std::cin >> x; --x; }
  std::vector<std::vector<std::pair<int, int>>> son(n+1);
  orep(i, 1, n) {
    int a, b, c; std::cin >> a >> b >> c;
    son[a].emplace_back(b, c);
    son[b].emplace_back(a, c);
  }
  const int inf = 0x3f3f3f3f;
  std::vector g(n+1, std::vector(1<<7, inf));
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    for(auto [x, c] : son[u]) {
      if (fa == x) { continue; }
      dfs(x, u);
    }
    int t = v[u] == -1 ? 0 : (1<<v[u]);
    g[u][t] = 0;
    orep(s, 0, 1<<7) {
      for(auto [x, c] : son[u]) {
        if (fa == x) { continue; }
        g[u][s|t] = std::min(g[u][s], g[x][s] + 2*c);
      }
    }
  };
  dfs(1, 0);

  std::vector f(n+1, std::vector(1<<7, inf));
  std::function<void(int, int)> dfs2 = [&](int u, int fa) {
    for(auto [x, c] : son[u]) {
      if (fa == x) { continue; }
      dfs2(x, u);
    }
    int t = v[u] == -1 ? 0 : (1<<v[u]);
    f[u][t] = 0;
    orep(s, 0, 1<<7) {
      for(auto [x, c] : son[u]) {
        if (fa == x) { continue; }
      }
    }
  };

  return 0;
}
