#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
std::vector<int> son[maxN];
const int M = 100003;
int dis[maxN];
int f[maxN];
bool vis[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  memset(dis, 0x3f, sizeof dis);
  orep(i, 0, m) {
    int l, r; std::cin >> l >> r;
    son[l].push_back(r);
    son[r].push_back(l);
  }
  std::queue<int> q;
  q.push({1}); dis[1] = 0; f[1] = 1;
  while(q.size()) {
    const int u = q.front();
    q.pop();
    if (vis[u]) { continue; } vis[u] = 1;
    for(auto v : son[u]) {
      if (vis[v] || dis[u] + 1 > dis[v]) { continue; }
      f[v] = (f[u]+f[v]) % M; dis[v] = dis[u] + 1;
      q.push({v});
    }
  }
  orep(i, 1, n+1) { std::cout << f[i]; NL; }

  return 0;
}
