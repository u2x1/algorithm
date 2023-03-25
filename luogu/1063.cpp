#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 4e2+5;
int arr[maxN];
long long dp[maxN][maxN];
long long ret;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    std::cin >> arr[i];
    arr[i+n] = arr[i];
  }
  orep(s, 1, n+1) orep(i, 0, 2*n-1) orep(k, i, i+s) {
    dp[i][i+s] = std::max(dp[i][i+s]
        , dp[i][k] + dp[k+1][i+s] + arr[i] * arr[k+1] * arr[i+s+1]);
  }
  orep(i, 0, n) {
    ret = std::max(ret, dp[i][i+n-1]);
  }
  std::cout << ret;

  return 0;
}
