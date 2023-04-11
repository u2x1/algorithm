#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
int arr[maxN];
int dp[maxN][3];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  memset(dp, 0x3f, sizeof dp);
  std::cin >> arr[1];
  dp[1][arr[1]+1] = 0;
  orep(i, 2, n+1) {
    std::cin >> arr[i];
    orep(l, -1, 2) {
      if (arr[i] >= l) {
        dp[i][arr[i]+1] = std::min(dp[i][arr[i]+1], dp[i-1][l+1]);
        // std::cout << "#1 dp " << i << "," << arr[i] << " ::: " << dp[i][arr[i]+1] << " on  " << l; NL;
      }
      if (arr[i]+l >= l && arr[i]+l <= 1) {
        dp[i][arr[i]+l+1] = std::min(dp[i][arr[i]+l+1], dp[i-1][l+1]+1);
        // std::cout << "#2 dp " << i << "," << arr[i]+l << " ::: " << dp[i][arr[i]+l+1]; NL;
      }
      if (arr[i]+l+l >= l && arr[i]+l+l <= 1) {
        dp[i][arr[i]+l+l+1] = std::min(dp[i][arr[i]+l+l+1], dp[i-1][l+1]+2);
        // std::cout << "#3 dp " << i << "," << arr[i]+l+l << " ::: " << dp[i][arr[i]+l+l+1]; NL;
      }
    }
  }
  int ret = std::min(std::min(dp[n][0], dp[n][1]), dp[n][2]);
  (ret > 0x3f3f3f3f ? (std::cout << "BRAK") : std::cout << ret);

  return 0;
}
