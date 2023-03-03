#include <iostream>
#include <algorithm>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;

int l[maxN], r[maxN];
long long dp[maxN][2];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n;
  std::cin >> n;
  orep(i, 1, n+1) {
    std::cin >> l[i] >> r[i];
  }
  l[0] = r[0] = 1;
  dp[0][0] = dp[0][1] = -1;
  orep(i, 1, n+1) {
    dp[i][0] = std::min(dp[i-1][0] + 1 + abs(r[i]-l[i-1]) + (r[i]-l[i])
        , dp[i-1][1] + 1 + abs(r[i]-r[i-1]) + (r[i]-l[i]));
    dp[i][1] = std::min(dp[i-1][0] + 1 + abs(l[i]-l[i-1]) + (r[i]-l[i])
        , dp[i-1][1] + 1 + abs(l[i]-r[i-1]) + (r[i]-l[i]));
    // std::cout << "#" << i; NL; std::cout << dp[i][0] << " " << dp[i][1];  NL;
  }
  std::cout << std::min(dp[n][0]+(n-l[n]), dp[n][1]+(n-r[n]));
  // std::cout << dp[n][1];

  return 0;
}
