#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e4+5;

struct edge { int u, v, c; } arr[50005];
bool operator<(const edge a, const edge b) { return a.c > b.c; }

int fa[maxN];
int find(const int x) { if (x == fa[x]) { return x; } return fa[x] = find(fa[x]); }

struct st { int u, c; };
std::vector<st> son[maxN];
int dp[maxN][20], faa[maxN][20];
int dep[maxN], lg[maxN];
bool vis[maxN];

void init(const int u = 1, const int faaa = 0, const int w = 0x3f3f3f3f) {
  vis[u] = 1;
  dep[u] = dep[faaa]+1;
  dp[u][0] = w; faa[u][0] = faaa;
  orep(i, 1, 20) {
    faa[u][i] = faa[faa[u][i-1]][i-1];
    dp[u][i] = std::min(dp[faa[u][i-1]][i-1], dp[u][i-1]);
  }
  for(const auto e : son[u]) {
    const auto v = e.u, cost = e.c;
    if (faaa == v) { continue; }
    init(v, u, cost);
  }
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) { std::swap(u, v); }
  while(dep[v] > dep[u]) {
    v = faa[v][lg[dep[v]-dep[u]]];
  }
  if (u == v) { return u; }
  while(faa[u][0] != faa[v][0]) {
    int i = 1;
    while(faa[u][i] != faa[v][i]) { ++i; }
    u = faa[u][i-1]; v = faa[v][i-1];
  }
  return faa[u][0];
}

int shortest(int u, int v) {
  const int p = lca(u, v);
  int ret = 0x3f3f3f3f;
  while(u != p) {
    ret = std::min(ret, dp[u][lg[dep[u]-dep[p]]]);
    u = faa[u][lg[dep[u]-dep[p]]];
  }
  while(v != p) {
    ret = std::min(ret, dp[v][lg[dep[v]-dep[p]]]);
    v = faa[v][lg[dep[v]-dep[p]]];
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  memset(dp, 0x3f, sizeof(dp));
  orep(i, 2, maxN) { lg[i] = lg[i>>1]+1; }
  orep(i, 0, m) {
    std::cin >> arr[i].u >> arr[i].v >> arr[i].c;
  }
  orep(i, 1, n+1) { fa[i] = i; }
  std::sort(arr, arr+m);
  orep(i, 0, m) {
    const edge &e = arr[i];
    if (find(e.u) == find(e.v)) { continue; }
    fa[find(e.u)] = find(e.v);
    son[e.u].push_back({e.v, e.c});
    son[e.v].push_back({e.u, e.c});
  }
  orep(i, 1, n+1) {
    if (vis[i]) { continue; }
    init(i);
  }
  int q; std::cin >> q;
  orep(i, 0, q) {
    int a, b; std::cin >> a >> b;
    if (find(a) != find(b)) { std::cout << -1; NL; continue; }
    std::cout << shortest(a, b); NL;
  }

  return 0;
}
