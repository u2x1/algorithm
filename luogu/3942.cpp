#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e5+5;
std::vector<int> son[maxN];
int f[maxN], g[maxN];

int k;

int ret;
const int INF = 0x3f3f3f3f;
void init(const int u = 1, const int faa = 0) {
  f[u] = -INF; g[u] = INF;
  for(const auto &v : son[u]) {
    if (v == faa) { continue; }
    init(v, u);
    f[u] = std::max(f[v]+1, f[u]);
    g[u] = std::min(g[v]+1, g[u]);
  }
  if (g[u] > k) { f[u] = std::max(f[u], 0); }
  if (f[u] >= k) { g[u] = 0; f[u] = -INF; ++ret; }
  if (f[u] + g[u] <= k) { f[u] = -INF; }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, _; std::cin >> n >> k >> _;
  if (k == 0) { std::cout << n; return 0; }
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b;
    son[a].emplace_back(b);
    son[b].emplace_back(a);
  }
  init();
  std::cout << ret + (f[1] >= 0);

  return 0;
}
