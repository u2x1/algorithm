#include <iostream>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e5+5;

struct st { long long cost, x; } cmd[505];
long long dp[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  orep(i, 0, m) {
    std::cin >> cmd[i].cost >> cmd[i].x;
  }
  dp[n] = 0;
  long long ret;
  for(int i = n; i >= 0; --i) {
    if (!~dp[i]) { continue; }
    for(int j = 0; j < m; ++j) {
      if (i <= cmd[j].x) { continue; }
      const auto t = i-(i%cmd[j].x);
      dp[t] = (~dp[t]) ? (std::min(dp[i] + cmd[j].cost, dp[t])) : (dp[i]+cmd[j].cost);
    }
    ret = dp[i];
  }
  std::cout << ret;
  return 0;
}
