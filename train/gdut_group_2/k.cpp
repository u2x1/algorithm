#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e5+5;
int w[maxN];
int fa[maxN]; int dis[maxN];

int find(const int u) {
  if (u == fa[u]) { return u; }
  const int old = fa[u];
  fa[u] = find(fa[u]);
  dis[u] += dis[old];
  return fa[u];
}

void setfa(const int u, const int faa) {
  const int fau = find(u);
  dis[fau] = 1; fa[fau] = faa;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    auto son = std::vector<std::vector<int>>(n+1, std::vector<int>());
    memset(dis, 0, sizeof(dis));
    orep(i, 2, n+1) {
      int a, b; std::cin >> a >> b;
      son[a].emplace_back(b);
      son[b].emplace_back(a);
    }
    std::vector<std::pair<int, int>> v;
    orep(i, 1, n+1) { fa[i] = i; std::cin >> w[i]; v.push_back({w[i], i}); }
    std::sort(v.begin(), v.end());
    for(const auto &[_, u] : v) {
      for(const auto &x : son[u]) {
        if (w[x] > w[u]) { continue; }
        setfa(x, u);
        // std::cout << "setting fa of " << x << " to " << u; NL;
      }
    }
    orep(i, 1, n+1) { find(i); std::cout << dis[i]+1; NL; }
  }

  return 0;
}
