#include <iostream>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
bool vis[maxN];

struct st { int u, len; };

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  if (n == 1) { std::cout << 0; return 0; }
  std::vector<std::vector<int>> e(n+1);
  int startCost;
  orep(i, 0, m) {
    int u, v, w; std::cin >> u >> v >> w;
    if (u == 1 || v == 1) { startCost = w; }
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  std::queue<st> q;
  int finalLen;
  vis[1] = 1;
  orep(i, 0ul, e[1].size()) { q.push({e[1][i], 1}); }
  while(!q.empty()) {
    const int u = q.front().u, len = q.front().len;
    q.pop();
    if (vis[u]) { continue; }
    if (u == n) { finalLen = len; break; }
    vis[u] = 1;
    orep(i, 0ul, e[u].size()) {
      q.push({e[u][i], len+1});
    }
  }
  if (finalLen == m) { std::cout << startCost+n-2; }
  else { std::cout << finalLen; }

  return 0;
}
