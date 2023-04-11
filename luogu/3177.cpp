#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
struct st { long long to, w; };
std::vector<st> son[maxN];
int sons[maxN];

long long dp[maxN][maxN];

int n, K;

int cntson(const int u = 1, const int fa = 0) {
  int cnt = 1;
  for(st s:son[u]) if(s.to != fa) { cnt += cntson(s.to, u); }
  return sons[u] = cnt;
}

int init(const int u = 1, const int fa = 0, const long long ww = 0) { 
  if (K) { dp[u][1] = ww*(K-1) + ww*(sons[u]-1)*(n-sons[u]-(K-1)); }
  dp[u][0] = ww*sons[u]*(n-sons[u]-K);
  int cnt = 1;
  for(const auto node : son[u]) {
    const int v = node.to, w = node.w;
    if (v == fa) { continue; }
    const int cur = init(v, u, w);
    cnt += cur;
    for(int j = std::min(K, cnt); j >= 0; --j) {
      for(int i = 0; i <= std::min(j, cur); ++i) {
        dp[u][j] = std::max(dp[u][j], dp[v][i] + dp[u][j-i]);
      }
    }
  }
  return cnt;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> K;
  if (!n) { std::cout << 0; return 0; }
  orep(i, 1, n) {
    long long u, v, w; std::cin >> u >> v >> w;
    son[u].push_back({v, w});
    son[v].push_back({u, w});
  }
  cntson(); init();
  std::cout << dp[1][K];

  return 0;
}
