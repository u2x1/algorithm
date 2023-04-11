#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 5e5+5;
std::vector<int> son[maxN];
int fa[maxN][20];
int dep[maxN];

void init(const int u = 1, const int faa = 0) {
  fa[u][0] = faa; dep[u] = dep[faa]+1;
  orep(i, 1, 20) {
    fa[u][i] = fa[fa[u][i-1]][i-1];
  }
  for(const auto v : son[u]) {
    if (v == faa) { continue; }
    init(v, u);
  }
}

int lg[maxN];
int lca(int u, int v) {
  if (dep[v] > dep[u]) { std::swap(u,v); }
  while(dep[u] > dep[v]) {
    u = fa[u][lg[dep[u]-dep[v]]];
  }
  if (u == v) { return u; }
  while(fa[u][0] != fa[v][0]) {
    int i = 1;
    while(fa[u][i] != fa[v][i]) { ++i; }
    u = fa[u][i-1]; v = fa[v][i-1];
  }
  return fa[u][0];
}

inline int cost(const int u, const int v) { const int a = lca(u, v); return dep[u]+dep[v]-2*dep[a]; }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 1, maxN) { lg[i] = lg[i-1] + (1<<(lg[i-1]+1) == i); }
  int n, m; std::cin >> n >> m;
  orep(i, 1, n) { int x, y; std::cin >> x >> y; son[x].emplace_back(y); son[y].emplace_back(x); }
  init();
  orep(i, 0, m) {
    int a, b, c; std::cin >> a >> b >> c;
    int x, y = 0x3f3f3f3f;
    {
      const int t = lca(a,b), ct = cost(a, t) + cost(b, t) + cost(c, t);
      if (ct < y) { x = t; y = ct; }
    }
    {
      const int t = lca(a,c), ct = cost(a, t) + cost(b, t) + cost(c, t);
      if (ct < y) { x = t; y = ct; }
    }
    {
      const int t = lca(b,c), ct = cost(a, t) + cost(b, t) + cost(c, t);
      if (ct < y) { x = t; y = ct; }
    }
    std::cout << x << " " << y; NL;
  }

  return 0;
}
