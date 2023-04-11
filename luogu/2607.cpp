#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'
#define int long long

const int maxN = 1e6+5;
int w[maxN], fa[maxN];
bool vis[maxN];
int dp[maxN][2];
std::vector<int> son[maxN];

void init(const int u, const int root) {
  dp[u][0] = 0; dp[u][1] = w[u];
  for(const auto v : son[u]) {
    vis[v] = 1;
    if (v == root) { dp[v][1] = -0x3f3f3f3f; }
    else {
      init(v, root);
      dp[u][0] += std::max(dp[v][0], dp[v][1]);
      dp[u][1] += dp[v][0];
    }
  }
}

int f(int u) {
  vis[u] = 1;
  while(!vis[fa[u]]) {
    u = fa[u]; vis[u] = 1;
  }
  init(u, u);
  int ret1 = std::max(dp[u][0], dp[u][1]);
  
  u = fa[u]; init(u, u);
  int ret2 = std::max(dp[u][0], dp[u][1]);
  return std::max(ret1, ret2);
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) { fa[i] = i; }
  orep(i, 1, n+1) {
    int tmp;
    std::cin >> w[i] >> tmp;
    son[tmp].emplace_back(i);
    fa[i] = tmp;
  }
  int ret = 0;
  orep(i, 1, n+1) {
    if (vis[i]) { continue; }
    ret += f(i);
  }
  std::cout << ret;


  return 0;
}
