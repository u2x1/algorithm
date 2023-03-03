#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int dp[maxN], arr[maxN];int cnt;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) { std::cin >> arr[n-i-1]; }
  dp[0] = arr[0]; cnt = 1;
  orep(i, 1, n) {
    auto it = std::upper_bound(dp, dp+cnt, arr[i], std::greater<int>());
    if (it == dp+cnt) { dp[cnt++] = arr[i]; }
    else { *it = arr[i]; }
  }
  std::cout << cnt;

  return 0;
}
