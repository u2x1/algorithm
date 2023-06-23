#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int a[maxN];

class DSU {
  std::vector<int> fa;
  public:
  DSU(int n) { fa = std::vector<int>(n+1); orep(i, 0, n+1) { fa[i] = i; } }
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) { fa[find(x)] = find(y); }
};

int val[maxN*2];
int fa[maxN*2][20], dep[maxN*2], ch[maxN*2][2];

int lca(int u, int v) {
  if (dep[u] < dep[v]) { std::swap(u, v); }
  while(dep[u] > dep[v]) {
    u = fa[u][std::__lg(dep[u]-dep[v])];
  }
  if (u == v) { return u; }
  for(int k = 19; ~k; --k) {
    if (fa[u][k] != fa[v][k]) { u = fa[u][k]; v = fa[v][k]; }
  }
  return fa[u][0];
}

void dfs(int u) {
  if (!u) { return; }
  dep[ch[u][0]] = dep[ch[u][1]] = dep[u] + 1;
  dfs(ch[u][0]); dfs(ch[u][1]);
}

int d;

int cost(int u, int v) {
  return abs(abs(a[u] - a[v]) - d);
}

void kruskal(std::vector<std::pair<int, int>> &edges, int n) {
  DSU dsu(2*n+1);
  int cur = n+1;
  for(auto [u, v] : edges) {
    if (dsu.find(u) == dsu.find(v)) { continue; }
    int fu = dsu.find(u), fv = dsu.find(v);
    fa[fu][0] = cur; fa[fv][0] = cur;
    ch[cur][0] = fu; ch[cur][1] = fv;
    val[cur] = cost(v, u);
    dsu.merge(fu, cur); dsu.merge(fv, cur);
    ++cur;
  }
  orep(k, 1, 20) {
    orep(i, 1, cur) {
      fa[i][k] = fa[fa[i][k-1]][k-1];
    }
  }
  dfs(cur-1);
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q, s; std::cin >> n >> q >> s >> d;
  orep(i, 1, n+1) { std::cin >> a[i]; }
  std::vector<std::pair<int, int>> edges;
  orep(i, 1, n+1) {
    int l = std::upper_bound(a+1, a+i, a[i]-d) - a;
    int r = std::upper_bound(a+i+1, a+n+1, a[i]+d) - a;
    auto checkPush = [&](int u) { if (u >= 1 && u <= n) { edges.push_back({u, i}); } };
    checkPush(l); checkPush(l-1);
    checkPush(r); checkPush(r-1);
  }
  std::sort(edges.begin(), edges.end(), [&](auto _a, auto _b) {
      return cost(_a.first, _a.second) < cost(_b.first, _b.second);
    });
  kruskal(edges, n);
  while(q--) {
    int k, i; std::cin >> i >> k;
    std::cout << (val[lca(s, i)] <= k ? "Yes" : "No"); NL;
  }

  return 0;
}
