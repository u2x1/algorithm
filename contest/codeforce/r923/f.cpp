#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct DSU {
  std::vector<int> fa;
  DSU (int n) : fa(n) { std::iota(all(fa), 0); }
  int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
  void merge(int u, int v) { fa[find(v)] = find(u); }
};

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    int n, m; std::cin >> n >> m;

    std::vector<std::array<int, 3>> egs(m);
    std::vector<int> d(n+1);
    for (auto &[c, a, b] : egs) { std::cin >> a >> b >> c; --a, --b; ++d[a], ++d[b]; }
    for (int i = 0; i < n; ++i) { d[i+1] += d[i]; }
    std::vector<int> G(2*m);
    for (auto &[c, a, b] : egs) {
      G[--d[a]] = b;
      G[--d[b]] = a;
    }
    std::vector<std::span<int>> adj(n);
    for (int i = 0; i < n; ++i) { adj[i] = std::span(G.begin()+d[i], G.begin()+d[i+1]); }

    DSU dsu(n);
    std::sort(egs.rbegin(), egs.rend());
    auto &mi = egs[0];
    for (auto &e : egs) {
      auto &[c, a, b] = e;
      if (dsu.find(a) == dsu.find(b)) { mi = std::min(mi, e); }
      dsu.merge(a, b);
    }
    // std::cout << mi[0] << " " << mi[1] + 1 << " " << mi[2] + 1; NL;

    std::vector<int> ret;
    std::vector<int> srch;
    std::vector<int> vis(n);
    vis[mi[1]] = 1;
    auto dfs = [&](auto &&self, int u) -> void {
      srch.emplace_back(u);
      if (u == mi[2]) { ret = srch; }
      for (auto v : adj[u]) {
        if (vis[v]) { continue; }
        if (u == mi[1] && v == mi[2]) { continue; }
        vis[v] = 1;
        self(self, v);
      }
      srch.pop_back();
    };
    dfs(dfs, mi[1]);
    std::cout << mi[0] << " " << ret.size(); NL;
    for (auto x : ret) { std::cout << x+1 << " "; } NL;
  }
  return 0;
}
