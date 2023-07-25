#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> son(n+1);
    std::vector<std::pair<int, int>> es;
    orep(i, 0, m) {
      int a, b; std::cin >> a >> b;
      son[a].emplace_back(b, i);
      es.emplace_back(a, b);
    }

    const int inf = 0x3f3f3f3f;
    std::vector<int> dis(n+1, inf), vis(n+1); 
    std::vector<int> visE(m+1);
    { // bfs
      std::queue<int> q;
      dis[1] = 0; vis[1] = 1;
      q.emplace(1);
      while(q.size()) {
        const int u = q.front(); q.pop();
        for(auto [v, idx] : son[u]) {
          if (vis[v]) { continue; }
          visE[idx] = 1;
          dis[v] = dis[u] + 1; vis[v] = 1; q.emplace(v);
        }
      }
    }

    bool flag = 1;
    orep(i, 0, n) {
      if (visE[i]) { continue; }
      auto [a, b] = es[i];
      if (dis[a]+1 != dis[b]) { flag = 0; break; }
    }
    std::cout << (flag ? "Yes" : "No"); NL;
  }

  return 0;
}
