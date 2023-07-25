#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> son(n+1);
  orep(i, 0, m) {
    int a, b, c; std::cin >> a >> b >> c;
    son[a].emplace_back(c, b);
  }
  const int inf = 0x3f3f3f3f;
  std::vector<std::vector<int>> dis(n+1, std::vector<int>(n+1, inf));
  const auto dij = [&](const int u) {
    std::priority_queue<std::pair<int, int>> q;
    q.push({0, u});
    while(q.size()) {
      auto [cost, v] = q.top(); q.pop();
      if (dis[u][v] < -cost) { continue; }
      for(auto [c, x] : son[v]) {
        // std::cerr << u << " " << x << '\n'; 
        if (dis[u][x] < -cost + c) { continue; }
        dis[u][x] = -cost + c;
        q.push({-dis[u][x], x});
      }
    }
  };

  orep(i, 1, n+1) { dij(i); }
  orep(i, 1, n+1) {
    int mi = inf;
    orep(j, 1, n+1) {
      // if ( mi > dis[i][j] + dis[j][i]) { std::cout << i << " " << j << " "<< dis[i][j] << " " << dis[j][i];  NL;}
      mi = std::min(mi, i == j ? dis[i][i] : dis[i][j] + dis[j][i]);
    }
    std::cout << (mi == inf ? -1 : mi); NL;
  }

  return 0;
}
