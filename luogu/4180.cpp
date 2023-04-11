#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'
#define int long long

const int maxN = 3e5+5;
struct st { int to, w; };
int dep[maxN], fa[maxN][20];
std::vector<st> son[maxN];
int lg[maxN];
struct edge { int a, b, c; } arr[maxN];
bool operator<(const edge x, const edge y) { return x.c < y.c; }
int longest[maxN][20][2];

void init(const int u = 1, const int faa = 0, const int w = 0) {
  fa[u][0] = faa; longest[u][0][0] = longest[u][0][1] = w; dep[u] = dep[faa]+1;
  orep(i, 1, 20) {
    fa[u][i] = fa[fa[u][i-1]][i-1];
    const int a = longest[u][i-1][0], b = longest[fa[u][i-1]][i-1][0],
              c = longest[u][i-1][1], d = longest[fa[u][i-1]][i-1][1];
    longest[u][i][0] = std::max(a, b);
    longest[u][i][1] = (a==b ? std::max(c,d) : std::max(std::min(a,b), std::max(c,d)));
    // std::cout << u << "," << i << ":::" << longest[u][i]; NL;
  }
  for(const auto v : son[u]) {
    if (v.to == faa) { continue; }
    init(v.to, u, v.w);
  }
}

int fab[maxN];
int find(const int u) { if (fab[u] == u) { return u; } return fab[u] = find(fab[u]); }

int lca(int u, int v) {
  if (dep[u] > dep[v]) { std::swap(u, v); }
  while(dep[v] > dep[u]) { v = fa[v][lg[dep[v]-dep[u]]]; }
  if (v == u) { return u; }
  while(fa[u][0] != fa[v][0]) {
    int i = 1; while(fa[u][i] != fa[v][i]) { ++i; }
    u = fa[u][i-1]; v = fa[v][i-1];
  }
  return fa[u][0];
}

std::pair<int,int> getmax(const int u, const int v) {
  const int t = lca(u, v);
  int ret = 0, ret2 = 0;
  for(int x = u; x != t; x = fa[x][lg[dep[x]-dep[t]]]) {
    ret2 = std::max(ret2, longest[x][lg[dep[x]-dep[t]]][1]);
    if (longest[x][lg[dep[x]-dep[t]]][0] > ret) {
      ret2 = ret;
      ret = longest[x][lg[dep[x]-dep[t]]][0];
    }
  }
  for(int x = v; x != t; x = fa[x][lg[dep[x]-dep[t]]]) {
    ret2 = std::max(ret2, longest[x][lg[dep[x]-dep[t]]][1]);
    if (longest[x][lg[dep[x]-dep[t]]][0] > ret) {
      ret2 = ret;
      ret = longest[x][lg[dep[x]-dep[t]]][0];
    }
  }
  return {ret, ret2};
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 1, maxN) { lg[i] = lg[i-1] + (1 << (lg[i-1]+1) == i); }
  int n, m; std::cin >> n >> m;
  orep(i, 1, n+1) { fab[i] = i; }
  orep(i, 0, m) {
    std::cin >> arr[i].a >> arr[i].b >> arr[i].c;
  }
  std::sort(arr, arr+m);
  std::vector<edge> unused;
  long long ret = 0;
  orep(i, 0, m) {
    const int x = arr[i].a, y = arr[i].b, c = arr[i].c;
    if (x == y) { continue; }
    if (find(x) == find(y)) { unused.emplace_back(arr[i]); continue; }
    fab[find(x)] = find(y);
    ret += c;
    son[x].push_back({y, c});
    son[y].push_back({x, c});
  }
  init();
  int delta = 1ll<<60;
  for(const auto z : unused) {
    const auto [x,y]  = getmax(z.a, z.b);
//    std::cout << z.a << " " << z.b << " " << z.c;
//    std::cout << ":::" << x << " " << y; NL;
    if (z.c - x) {
      delta = std::min(z.c - x, delta);
    } else {
      delta = std::min(z.c - y, delta);
    }
  }

  std::cout << ret + delta;
//  NL; std::cout << delta;

  return 0;
}
