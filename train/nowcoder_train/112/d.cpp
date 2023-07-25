#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using pli = std::pair<long long, int>;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, s; std::cin >> n >> m >> s; s--;
  std::vector<std::vector<std::array<int, 3>>> adj(n);
  orep(i, 0, m) {
    int k, t; std::cin >> k >> t;
    int l; std::cin >> l; --l;
    orep(i, 1, k) {
      int x; std::cin >> x; --x;
      adj[l].push_back({x, i-1, t});
      l = x;
    }
  }
  std::priority_queue<pli, std::vector<pli>, std::greater<pli>> q;
  using i64 = long long;
  const i64 inf = 1ll << 62;
  std::vector<i64> dis(n, inf);
  dis[s] = 0;
  q.emplace(0, s);
  while(not q.empty()) {
    auto [d, v] = q.top(); q.pop();
    // if (dis[v] <= d) { continue; }
    for(auto [x, i, t] : adj[v]) {
      i64 d2 = d + ((i - d) % t + t) % t;
      d2 = 1 + (d2 < i ? i : d2);
//       std::cout << "from " << v << " to " << x << " cost " << d2; NL;
      if (d2 < dis[x]) {
        dis[x] = d2;
        q.emplace(d2, x);
      }
    }
  }
  orep(i, 0, n) { std::cout << (dis[i] == inf ? -1 : dis[i]); NL; }

  return 0;
}
