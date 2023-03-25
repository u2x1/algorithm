#include <iostream>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

struct e { int x, u; };
std::vector<e> son[maxN];

long long ret;
long long dp[maxN][2];

int cur;

void dfs(int u, int fa){
  dp[u][0] = 1;
  for(auto &v : son[u]) {
    if (v.u == fa) { continue; }
    dfs(v.u, u);
    if (v.x & 1) {
      ret += (1ll<<cur) * (dp[u][0]*dp[v.u][0] + dp[u][1]*dp[v.u][1]);
      dp[u][1] += dp[v.u][0];
      dp[u][0] += dp[v.u][1];
    } else {
      ret += (1ll<<cur) * (dp[u][1]*dp[v.u][0] + dp[u][0]*dp[v.u][1]);
      dp[u][1] += dp[v.u][1];
      dp[u][0] += dp[v.u][0];
    }
    v.x >>= 1;
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n) {
    int a, b, x;
    std::cin >> a >> b >> x;
    son[a].push_back({x, b});
    son[b].push_back({x, a});
  }
  orep(i, 0, 32) {
    memset(dp, 0, sizeof(dp));
    dfs(1, 0);
    ++cur;
  }
  std::cout << ret;


  return 0;
}
