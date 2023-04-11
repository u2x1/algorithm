#include <iostream>
#include <cstring>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int mod = 998244353;
int dp[305][305][305] = {1};
std::set<std::pair<long long, long long>> no;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, m; std::cin >> n >> m;
  long long A, B, C, D, E, F; std::cin >> A >> B >> C >> D >> E >> F;
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    no.insert({a, b});
  }
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; i+j <= n; ++j) {
      for(int k = 0; i+j+k <= n; ++k) {
        if (no.find(std::make_pair(i*A+j*C+k*E, i*B+j*D+k*F)) != no.end()) { continue; }
        if (i && dp[i-1][j][k]) { dp[i][j][k] += dp[i-1][j][k]; dp[i][j][k] %= mod; }
        if (j && dp[i][j-1][k]) { dp[i][j][k] += dp[i][j-1][k]; dp[i][j][k] %= mod; }
        if (k && dp[i][j][k-1]) { dp[i][j][k] += dp[i][j][k-1]; dp[i][j][k] %= mod; }
//        if (dp[i][j][k]) { std::cout << i << " " <<j << " " << k; NL; }
      }
    }
  }
  long long ret = 0;
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; i+j <= n; ++j) {
      ret += dp[i][j][n-i-j];
      ret %= mod;
    }
  }
  std::cout << ret;

  return 0;
}
