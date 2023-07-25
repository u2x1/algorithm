#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  std::vector<std::vector<std::pair<int, int>>> g(n+1);
  std::vector<std::pair<int, int>> e(m);
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    g[a].emplace_back(b, i);
    g[b].emplace_back(a, i);
    e[i] = { a, b };
  }
  const int inf = 0x3f3f3f3f;

  std::vector<int> hasinf(m, 1);
  std::vector<int> dead(n+1, 0);
  std::vector<int> dis(n+1, inf);
  std::vector<std::vector<int>> son(n+1);
  long long ret = 1; dis[1] = 0;
  { // bfs
    std::queue<int> q; q.emplace(1);
    while(q.size()) {
      const int u = q.front(); q.pop();
      for(auto [x, idx] : g[u]) {
        if (dis[x] != inf) { continue; }
        q.emplace(x); dis[x] = dis[u] + 1;
        hasinf[idx] = 0;
        son[u].emplace_back(x);
        if (dis[x] <= k) { ++ret; }
      }
    }
  }
  orep(i, 0, m) {
    if (!hasinf[i]) { continue; }
    auto [u, v] = e[i];
    if (dis[u] == inf || dis[v] == inf) { continue; }
    dead[u] = dead[v] = 1;
    ret += std::max(0, k - dis[u]);
    ret += std::max(0, k - dis[v]);
    // std::cout << u << " " << v << " " << ret; NL;
  }
  orep(i, 2, n+1) {
    if (son[i].size() == 0 && !dead[i]) {
      // std::cout << ret; NL;
      ret += std::max(0, k - dis[i]);
    }
  }
  std::cout << ret;

  return 0;
}
