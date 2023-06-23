#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> sum {0};
  std::vector<int> v(n); for(auto &x : v) { std::cin >> x; sum.emplace_back(sum.back()+x); }
  std::vector dp(n+5, std::vector(n+5, 0));
  dp[0][1] = 1;
  const int mod = 1e9+7;
  int ret = 0;
  orep(i, 0, n-1) {
    for(int j = n; j > 1; --j) {
      dp[sum[i+1]%j][j] += dp[sum[i+1]%(j-1)][(j-1)];
      dp[sum[i+1]%j][j] %= mod;
    }
  }
  orep(i, 1, n+1) { ret = (ret + dp[sum.back()%i][i]) % mod; }
  std::cout << ret;

  return 0;
}
