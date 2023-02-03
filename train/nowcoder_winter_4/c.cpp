#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e2+5;
long long dp[maxN];
int w[maxN], v[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, n) {
    std::cin >> w[i] >> v[i];
  }
  orep(k, 0, n) {
    memset(dp, 0ll, sizeof(long long)*(m+1));
    for(int i = 0; i < n; ++i) {
      if (i == k) { continue; }
      for(int j = m; j-w[i] >= 0; --j) {
        dp[j] = std::max(dp[j], dp[j-w[i]] + v[i]);
      }
    }
    if (dp[m] < dp[m-w[k]] + v[k]) { std::cout << 0; NL; continue; }
    std::cout << dp[m] - (dp[m-w[k]] + v[k]) + 1ll; NL;
  }

  return 0;
}
