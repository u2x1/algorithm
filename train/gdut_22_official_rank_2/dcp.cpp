#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

const int INF = 0x3f3f3f3f;

int f[N],g[N];

void dfs(int u,int fa) {
  f[u] = g[u] = -INF;
  if (a[u] == 1) f[u] = 1;
  if (a[u] == 2) g[u] = 1;
  for (auto v:son[u]) if (v != fa) {
    dfs(v,u);
    ret1 = max(ret1,f[u]+f[v]);
    ret2 = max(ret2,max(f[u]+g[v],f[v]+g[u]));
    if (a[u] == 1) {
      f[u] = max(f[u],f[v]+1);
      g[u] = max(g[u],g[v]+1);
    }
    if (a[u] == 2) {
      g[u] = max(g[u],f[v]+1);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);

  return 0;
}
