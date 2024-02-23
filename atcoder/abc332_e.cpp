#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cout << std::setprecision(15) << std::fixed;
  int n, d; std::cin >> n >> d;
  std::vector<double> v(n);
  for (int i = 0; i < n; ++i) { std::cin >> v[i]; }
  double avg = std::accumulate(all(v), 0.) / d;
  std::vector dp(d+1, std::vector<double>(1<<n, linf));
  for (int s = (1 << n) - 1; s > -1; --s) {
    double c = 0;
    for (int i = 0; i < n; ++i) {
      if ((s >> i) & 1) { c += v[i]; }
    }
    dp[1][s] = (c - avg) * (c - avg);
  }
  for (int i = 2; i <= d; ++i) {
    for (int s = (1 << n) - 1; s > -1; --s) {
      dp[i][s] = std::min(dp[i][s], dp[i-1][s] + dp[1][0]);
      for (int p = s; p; p = (p-1) & s) {
        dp[i][s] = std::min(dp[i][s], dp[i-1][s^p] + dp[1][p]);
      }
    }
  }
  std::cout << dp[d][(1 << n) - 1] / d;

  return 0;
}
