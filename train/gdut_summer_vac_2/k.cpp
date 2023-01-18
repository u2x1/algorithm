#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 1e3+5;
int dp[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t, m; std::cin >> t >> m;
  orep(i, 0, m) {
    int c, v; std::cin >> c >> v;
    for(int j = t - c; j >= 0; --j) {
      dp[j+c] = std::max(dp[j] + v, dp[j+c]);
    }
  }
  std::cout << dp[t];

  return 0;
}
