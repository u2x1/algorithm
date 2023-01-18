#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  char c1, c2;
  int h1, m1, h2, m2; std::cin >> h1 >> c1 >> m1 >> h2 >> c2 >> m2;
  int mins = m2 - m1;
  if (mins < 0) { mins = (h2-h1-1) * 60 + (mins + 60); }
  else { mins += (h2-h1)*60; }
  std::vector<long long> dp(mins+1, 0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    int t, v, times; std::cin >> t >> v >> times;
    if (!times) {
      for(int j = t; j <= mins; ++j) {
        dp[j] = std::max(dp[j-t] + v, dp[j]);
      }
    } else {
      for (int k = 1; times; k <<= 1) {
        if (times < k<<1) {
          k = times - (k-1);
          times = 0;
        }
        for(int j = mins-t*k; j >= 0; --j) {
          dp[j+t*k] = std::max(dp[j] + v*k, dp[j+t*k]);
        }
      }
    }
  }
  std::cout << dp[mins];

  return 0;
}

