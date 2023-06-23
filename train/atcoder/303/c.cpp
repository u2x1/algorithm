#include <iostream>
#include <vector>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
int arr[maxN];
int dp[maxN][maxN];
std::vector<int> son[maxN];
bool vis[maxN];

int dfs(int u) {
  if (vis[u]) { return 0; }
  vis[u] = 1;
  int ret = 1;
  for(auto x : son[u]) { ret += dfs(x); }
  return ret;
}
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n>> m;
  memset(dp, 0x3f, sizeof(dp));
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    son[a].emplace_back(b);
  }
  int ret = 0;
  orep(i, 1, n+1) {
    memset(vis, 0, sizeof(vis));
    ret += dfs(i);
  }
  std::cout << ret;

  return 0;
}
