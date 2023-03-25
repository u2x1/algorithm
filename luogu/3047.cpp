#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e5+5;
int arr[maxN];
std::vector<int> son[maxN];
long long dp[maxN][25];
long long dp2[maxN][25];
int n, k;

void dfs(int u = 1, int fa = 0) {
  orep(i, 0, k+1) {
    dp[u][i] = arr[u];
  }
  for(const auto v : son[u]) {
    if (v==fa) { continue; }
    dfs(v, u);
    orep(i, 1, k+1) {
      dp[u][i] += dp[v][i-1];
    }
  }
}

void dfs2(const int u = 1, const int fa = 0) {
  dp2[u][0] = arr[u];
  orep(i, 1, k+1) {
    dp2[u][i] = dp[u][i] + dp2[fa][i-1] - (i-2 >= 0 ? dp[u][i-2] : 0);
  }
  for(const auto v : son[u]) {
    if (v == fa) { continue; }
    dfs2(v, u);
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> k;
  orep(i, 1, n) {
    int u, v; std::cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  orep(i, 1, n+1) { std::cin >> arr[i]; }
  dfs();
  orep(i, 1, k+1) { dp2[0][i] = dp[1][i-1]; }
  dfs2();
  orep(i, 1, n+1) { std::cout << dp2[i][k]; NL; }

  return 0;
}
