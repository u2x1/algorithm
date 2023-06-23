#include <iostream>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

using i64 = long long;

const int maxN = 2e3+5;
struct st { long long to, w; };
std::vector<st> son[maxN];
int sons[maxN];

i64 dp[maxN][maxN];

int n, K;

void init(const int u = 1, const int fa = 0) { 
  sons[u] = 1;
  dp[u][0] = dp[u][1] = 0;
  for(const auto &node : son[u]) {
    const i64 &v = node.to;
    if (v == fa) { continue; }
    init(v, u); sons[u] += sons[v];
  }
  for(const auto node : son[u]) {
    const i64 v = node.to, w = node.w;
    if (v == fa) { continue; }
    for(int j = std::min(K, sons[u]); j >= 0; --j) {
      // if (n-sons[u] >= K-j) { dp[u][j] += dp[v][0] + w*(sons[v])*(n-sons[v]-K); }
      for(int i = std::max(0, j-(sons[u]-sons[v])); i <= std::min(j, sons[v]); ++i) {
        // if (sons[u]-sons[v] < j-i) { continue; }
        i64 val = w*(K-i)*i + w*(sons[v]-i)*(n-sons[v]-(K-i));
        dp[u][j] = std::max(dp[u][j], val + dp[u][j-i] + dp[v][i]);
        // if (dp[u][j-i] < 0) { std::cout << "transfering dp " << u << ',' << j << " using " << u << ',' << j-i; NL; }
      }
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> K;
  memset(dp, -0x3f, sizeof(dp));
  if (!n) { std::cout << 0; return 0; }
  orep(i, 1, n) {
    long long u, v, w; std::cin >> u >> v >> w;
    son[u].push_back({v, w});
    son[v].push_back({u, w});
  }
  init();
  std::cout << dp[1][K];

  return 0;
}
