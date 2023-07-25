#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector adj(n+1, std::vector<std::array<int, 3>>());
  orep(i, 0, m) {
    int a, b, c; std::cin >> a >> b >> c;
    adj[a].push_back({b, c, i});
    adj[b].push_back({a, c, i});
  }
  std::priority_queue<std::pair<int, int>> q;
  const int inf = 1ll << 62;
  std::vector<int> dis(n+1, inf);
  std::vector<int> fa(n+1, -1);
  q.push({0, 1}); dis[1] = 0;
  while(q.size()) {
    const auto [c, u] = q.top(); q.pop();
    if (dis[u] < -c) { continue; }
    for(auto [v, cost, idx] : adj[u]) {
      if (dis[v] <= cost + dis[u]) { continue; }
      fa[v] = idx;
      dis[v] = cost + dis[u];
      q.push({-dis[v], v});
    }
  }
  for(auto x : fa) {
    if (~x) { std::cout << x+1 << " "; }
  }

  return 0;
}
