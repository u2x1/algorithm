#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::vector<int>> dp(150, std::vector<int>(n+2));
  int ret = 0;
  orep(i, 1, n+1) {
    int x; std::cin >> x;
    dp[x][i] = i+1;
  }
  orep(k, 1, 150) {
    orep(i, 1, n+1) {
      if (!dp[k][i]) {
        dp[k][i] = dp[k-1][dp[k-1][i]];
      }
      if(dp[k][i]) { ret = k; }
    }
  }
  std::cout << ret;

  return 0;
}
