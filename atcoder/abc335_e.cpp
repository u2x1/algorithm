#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<int> val(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> val[i];
  }
  std::vector<std::vector<int>> son(n);
  for (int i = 0; i < m; ++i) {
    int a, b; std::cin >> a >> b; --a, --b;
    if (val[a] <= val[b]) { son[a].emplace_back(b); }
    if (val[b] <= val[a]) { son[b].emplace_back(a); }
  }
  std::priority_queue<std::array<int, 3>> q;
  std::vector<int> vis(n);
  q.push({-val[0], 1, 0});
  while (!q.empty()) {
    auto [_, dep, u] = q.top(); q.pop();
    if (vis[u]) { continue; }
    vis[u] = 1;
    if (u == n-1) { std::cout << dep; return 0; }
    for (auto x : son[u]) {
      q.push({-val[x], dep + (val[x] != val[u]), x});
    }
  }
  std::cout << 0; return 0;

  return 0;
}
