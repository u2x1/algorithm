#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
bool p[maxN];
bool vis[maxN];
std::vector<int> son[maxN];
std::vector<int> dis[maxN];
int has[maxN];
int N, M; 

void bfs(int u, int limit) {
  std::queue<std::pair<int, int>> q({{u, 0}});
  while(q.size()) {
    auto [v, d] = q.front(); q.pop();
    if (limit == d) { dis[u].emplace_back(v); continue; }
    p[v] = 1;
    for(auto x : son[v]) {
      if (vis[x]) { continue; }
      vis[x] = 1; q.emplace(x, d+1);
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> M;
  orep(i, 0, M) {
    int l, r; std::cin >> l >> r;
    son[l].emplace_back(r);
    son[r].emplace_back(l);
  }
  int K; std::cin >> K;
  std::vector<int> qrs;
  memset(has, -1, sizeof(has));
  orep(i, 0, K) { 
    memset(vis, 0, sizeof(vis));
    int u, d; std::cin >> u >> d;
    if (~has[u] && has[u] != d) { std::cout << "No"; exit(0); }
    has[u] = d;
    qrs.emplace_back(u);
    vis[u] = 1;
    bfs(u, d);
  }
  for(auto x : qrs) {
    if (dis[x].size() == 0) { std::cout << "No"; exit(0); }
    bool hit = 0;
    for(auto z : dis[x]) { if (!p[z]) { hit = 1; break; } }
    if (!hit) { std::cout << "No"; exit(0); } 
  }
  std::cout << "Yes"; NL;
  orep(i, 1, N+1) { std::cout << (!p[i]); }

  return 0;
}
