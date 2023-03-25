#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e6+5;
int arr[maxN];
int dp[maxN][2];
const int mod = 1e9+7;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n,k; std::cin >> n >> k;
  if (k == 1) { std::cout << 1; return 0; }
  dp[0][0] = 1;
  long long sum = dp[0][0], len = 1;
  orep(i, 1, n+1) {
    dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
    dp[i][1] = sum;
    sum = (dp[i][0] + sum) % mod; ++len;
    if (len == k) { sum = (sum - dp[i-k+1][0] + mod) % mod; --len; }
  }
  std::cout << (dp[n][1] + dp[n][0]) % mod;

  return 0;
}
