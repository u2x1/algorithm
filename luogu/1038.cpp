#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e2+5;
int arr[maxN];
struct st { int to, w; };
std::vector<st> son[maxN];
int U[maxN], C[maxN];
int in[maxN];
bool vis[maxN];
bool dead[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, p; std::cin >> n >> p;
  orep(i, 1, n+1) { std::cin >> C[i] >> U[i]; }
  orep(i, 0, p) {
    int a, b, c; std::cin >> a >> b >> c;
    son[a].push_back({b, c});
    son[b].push_back({a, c});
  }
  std::queue<int> q;
  orep(i, 1, n+1) {
    if (C[i]) { q.push(i); dead[i] = 1; U[i] = 0; continue; }
  }
  if (q.size() == n) {
    orep(u, 1, n+1) {
      std::cout << u << " " << C[u]; NL;
    }
    return 0;
  }
  std::vector<int> out;
  while(q.size()) {
    const int u = q.front(); q.pop();
    C[u] -= U[u];
    if (C[u] <= 0) { continue; }
    bool alldead = 1;
    for(const auto node : son[u]) {
      const int v = node.to, w = node.w;
      C[v] += w*C[u];
      if (!dead[v]) { q.push(v); dead[v] = 1; alldead = 0; }
    }
    if (alldead) { out.push_back(u); }
  }
  bool null = 1;
  std::sort(out.begin(), out.end());
  for(const auto u : out) {
    if (C[u] > 0) {
      null = 0;
      std::cout << u << " " << C[u]; NL;
    }
  }
  if (null) { std::cout << "NULL"; }
  return 0;
}
