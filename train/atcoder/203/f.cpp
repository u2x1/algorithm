#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  std::vector<int> v(n+1);
  orep(i, 1, n+1) { std::cin >> v[i]; }
  std::sort(v.begin(), v.end());
  const auto f = [&](int x) { return std::upper_bound(v.begin(), v.end(), v[x]/2) - v.begin() - 1; };
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(41, 0x3f3f3f3f));
  orep(i, 0, n+1) { dp[i][0] = i; }
  // dp[0][1] = 0;
  orep(i, 1, n+1) {
    orep(j, 1, 32) {
      dp[i][j] = std::min(dp[f(i)][j-1], dp[i-1][j] + 1);
    }
  }
  for(int j = 0; ; ++j) {
    if (dp[n][j] <= k) {
      std::cout << j << " " << dp[n][j];
      return 0;
    }
  }

  return 0;
}
