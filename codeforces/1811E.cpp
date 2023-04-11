#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;

long long dp[20][10];
long long sum[20];

void init() {
  sum[0] = 1;
  orep(i, 1, 20) {
    orep(x, 1, 10) {
      if (x == 4) { continue; }
      if (x == 5) { dp[i][x] = dp[i][x-2] + sum[i-1]; continue; }
      dp[i][x] = dp[i][x-1] + sum[i-1];
    }
    sum[i] = sum[i-1] + dp[i][9];
  }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  init();
  int t; std::cin >> t;
  while(t--) {
    long long k; std::cin >> k;
    long long ret = 0;
    for(int i = 19; i > 0; --i) {
      for(int x = 9; x >= 0; --x) {
        if (x == 4) { continue; }
        if (dp[i][x] <= k) {
          ret = ret*10 + x;
          k -= dp[i][x];
          break;
        }
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}
