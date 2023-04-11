#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
std::vector<int> son[maxN];
int dep[maxN];
int dret, bret;
int color[maxN], dfn[maxN];
int fa[maxN];

void dfs(const int u = 1, const int faa = 0, const int d = 1) {
  dep[u] = d;
  fa[u] = faa;
  dret = std::max(dret, d);
  for(const auto v : son[u]) {
    if (v == faa) { continue; }
    dfs(v, u, d+1);
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n) {
    int u, v;
    std::cin >> u >> v;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  dfs();
  std::map<int, int> b;
  orep(i, 1, n+1) { b[dep[i]]++; }
  for(const auto [x,y] : b) { bret = std::max(bret, y); }
  std::cout << dret; NL;
  std::cout << bret; NL;
  int x, y; std::cin >> x >> y;
  int t = 0;
  while(x || y) {
    ++t;
    // std::cout << x << " " << y; NL;
    if (x) {
      if (dfn[x]) { std::cout << (dfn[x]-1)+2*(t-1); return 0; }
      dfn[x] = t; x = fa[x];
    }
    if (y) {
      if (dfn[y]) { std::cout << 2*(dfn[y]-1)+t-1; return 0; }
      dfn[y] = t; y = fa[y];
    }
  }

  return 0;
}
