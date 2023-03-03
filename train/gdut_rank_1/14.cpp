#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e4+5;
bool vis[maxN];
struct st { int u; int depth; };

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> son(n+1);
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    son[a].push_back(b);
    son[b].push_back(a);
  }
  orep(i, 0, k) {
    memset(vis, 0, sizeof(vis));
    int uu; std::cin >> uu;
    int farest = -1; int d = -1;;
    if (son[uu].size() == 0) {
      std::cout << 0; NL; continue;
    }
    std::queue<st> q;
    q.push({uu, 0}); vis[uu] = 1;
    while(!q.empty()) {
      const int u = q.front().u, dd = q.front().depth; q.pop();
      if (d < dd || (d==dd && u < farest)) {
        farest = u; d = dd;
      }
      orep(j, 0ul, son[u].size()) {
        const int v = son[u][j];
        if (vis[v]) { continue; } vis[v] = 1;
        q.push({v, dd+1});
      }
    }
    std::cout << farest; NL;
  }

  return 0;
}
