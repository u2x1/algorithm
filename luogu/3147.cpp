#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 3e5+5;
int arr[maxN];
int dp[maxN][60];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1){
    std::cin >> arr[i];
    dp[i][arr[i]] = i;
  }
  int ret = 0;
  orep(k, 1, 60) {
    orep(i, 1, n+1) {
      if (dp[i][k-1] && dp[dp[i][k-1]+1][k-1]) {
        dp[i][k] = dp[dp[i][k-1]+1][k-1];
        // std::cout << i << " " << k-1 <<  " " << dp[i][k-1]; NL;
        ret = std::max(ret, k);
      }
    }
  }
  std::cout << ret;

  return 0;
}
