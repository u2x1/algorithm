#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

const int maxN = 1e7+5;
long long dp[4][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N, K; std::cin >> N >> K;
  dp[0][0] = 1;
  orep(i, 0, 3) {
    orep(j, 0, 3*N+1) {
      dp[i+1][j+1] += dp[i][j];
      dp[i+1][j+N+1] -= dp[i][j];
    }
    orep(j, 1, 3*N+1) {
      dp[i+1][j] += dp[i+1][j-1];
    }
  }
  int k = K;
  int x;
  for(x = 3; k > dp[3][x] ; ++x) {
    k -= dp[3][x];
    // std::cout << k; NL;
  }
  for(int i = 1; i <= x; ++i) {
    int l = x-i-std::min(N, x-i-1);
    int r = std::min(N, x-i-1);
    if (l > r) { continue; }
    // std::cout << l << " " << r << " " << k; NL;
    // if (i == 1000000) { exit(0); }
    const int y = r - l + 1;
    // std::cout << l << " " << r << " " << y; NL;
    if (k > y) { k -= y; continue; }
    std::cout << i << " " << l+k-1 << " " << x-i-(l+k-1);
    return 0;
  }

  return 0;
}
