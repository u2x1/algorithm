#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

const int mo = 998244353;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<lnt> v(n);
  std::vector<lnt> dp(n);
  dp[0] = 1;
  const int N = std::sqrt(n) + 1;
  std::vector a(N, std::vector<lnt>(N));
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
    for (int j = 1; j < N; ++j) {
      dp[i] = (dp[i] + a[j][i % j]) % mo;
    }
    if (v[i] < N) {
      (a[v[i]][i % v[i]] += dp[i]) %= mo;
    } else {
      for (int j = i+v[i]; j < n; j += v[i]) {
        (dp[j] += dp[i]) %= mo;
      }
    }
  }
  lnt ret = 0;
  for (int i = 0;i < n; ++i) {
    (ret += dp[i]) %= mo;
  }
  std::cout<< ret;


  return 0;
}
