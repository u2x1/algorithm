#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int fa[maxN], d[maxN];

int find(const int u) {
  if (fa[u] == u) { return u; }
  const int ori = fa[u];
  fa[u] = find(fa[u]);
  d[u] += d[ori];
  return fa[u];
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  orep(i, 1, t+1) { fa[i] = i; }
  int ret = 0x3f3f3f3f;
  orep(u, 1, t+1) {
    int v; std::cin >> v;
    if (find(u) != find(v)) { fa[u] = fa[v]; d[u] = d[v]+1;  }
    else {
      ret = std::min(ret, d[v]+1);
    }
  }
  std::cout << ret;
  return 0;
}
