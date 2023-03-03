#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 3e2+5;
int dp[maxN][maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  int ret = 0;
  orep(i, 0, n) {
    std::cin >> dp[i][i];
    ret = std::max(ret, dp[i][i]);
  }
  
  orep(s, 1, n) {
    orep(i, s, n) {
      const int l = i-s, r = i;
      orep(k, l, r) {
        if (dp[l][k] == dp[k+1][r] && dp[l][r] < dp[l][k]+1) {
          dp[l][r] = dp[l][k]+1;
          ret = std::max(ret, dp[l][r]);
        }
      }
    }
  }

  std::cout << ret;
  return 0;
}
