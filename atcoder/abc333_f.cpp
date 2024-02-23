#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  const int mo = 998244353;
  auto ksm = [&](lnt x, int e) {
    lnt ret = 1;
    while (e) {
      if (e & 1) { (ret *= x) %= mo; }
      (x *= x) %= mo; e /= 2;
    }
    return ret;
  };
  auto inv = [&](int x) {
    return ksm(x, mo-2);
  };
  int n; std::cin >> n;
  std::vector dp(n+1, std::vector<lnt>(n+1));
  lnt inv2 = inv(2);
  dp[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    lnt a = 1, b = 0;
    for (int j = 2; j <= i; ++j) {
      a = a * inv2 % mo;
      b = (b + dp[i-1][j-1]) * inv2 % mo;
    }
    // (a *= inv2) %= mo; (b *= inv2) %= mo;
    dp[i][1] = b * inv(2 - a + mo) % mo;
    for (int j = 2; j <= n; ++j) {
      dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) * inv2 % mo;
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << dp[n][i] << " ";
  }

  return 0;
}
