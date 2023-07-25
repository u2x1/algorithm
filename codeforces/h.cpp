#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> son(n+1);
    orep(i, 0, m) {
      int a, b, c; std::cin >> a >> b >> c;
      son[a].emplace_back(b, c);
      son[b].emplace_back(a, -c);
    }
    std::vector<int> vis(n+1), dis(n+1);
    bool no = 0;
    orep(i, 1, n+1) {
      if (vis[i]) { continue; }
      std::queue<std::pair<int, int>> q; q.emplace(i, 0);
      while(q.size()) {
        auto [u, d] = q.front(); q.pop();
        for(auto [v, dd] : son[u]) {
          if (!vis[v]) {
            dis[v] = d + dd; vis[v] = 1;
            q.emplace(v, d+dd);
          } else if (dis[v] != d+dd) { no = 1; }
        }
      }
    }
    std::cout << (no ? "NO" : "YES"); NL;
  }

  return 0;
}
