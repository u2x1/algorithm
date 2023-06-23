#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e4+5;
int w[maxN];
bool vis[maxN];
bool md;
long long ret[maxN];

void dfs(const std::vector<std::vector<int>> &son, const int u, const int add, const int val=0) {
  if (vis[u] == md) { return; }
  vis[u] = md;
  const int curval = std::__gcd(val, w[u]);
  ret[curval] += add;
  for(auto v : son[u]) { dfs(son, v, add, curval); }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    orep(i, 1, n+1) { std::cin >> w[i]; }
    std::vector<std::vector<int>> son(n+1, std::vector<int>());
    orep(i, 2, n+1) {
      int fa; std::cin >> fa;
      son[fa].emplace_back(i);
      son[i].emplace_back(fa);
    }
    memset(ret, 0, sizeof ret);
    orep(i, 1, n) {
      md = !md;
      dfs(son, i, 1);
    }
    while(m--) {
      int op; std::cin >> op;
      if (op == 0) {
        int u, c; std::cin >> u >> c;
   //  w[u] = c;
   //  memset(ret, 0, sizeof ret);
   //  orep(i, 1, n) {
   //    md = !md;
   //    dfs(son, i, 1);
   //  }
        // md = !md;
        // dfs(son, u, -2);
        // w[u] = c;
        // dfs(son, u, 2);
      } else {
        int k; std::cin >> k;
        std::cout << ret[k]/2; NL;
      }
    }
  }

  return 0;
}
