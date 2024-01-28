#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int mod = 1e9+7;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  std::vector dp(n+5, std::vector(n+5, 0ll));
  std::vector sum(n+5, std::vector(n+5, 0ll));
  int o = 2;
  std::vector<char> v(n+5);
  for(auto c : s) { v[o++] = (c == '<'); }
  dp[1][1] = 1;
  for(int x = 1; x <= n; ++x) {
    (sum[1][x] = dp[1][x] + sum[1][x-1]) %= mod;
  }
  for(int i = 2; i <= n; ++i) {
    for(int x = 1; x <= i; ++x) {
      (dp[i][x] = v[i] ? sum[i-1][x-1] : sum[i-1][i-1] - sum[i-1][x-1]) %= mod;
      (sum[i][x] = sum[i][x-1] + dp[i][x]) %= mod;
    }
  }
  std::cout << ((sum[n][n] % mod) + mod) % mod;

  return 0;
}
