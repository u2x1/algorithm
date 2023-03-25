#include <iostream>
#include <cstring>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
const int mod = 1e9+7;
int arr[maxN];
long long dp[3];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    memset(dp, 0, sizeof(dp));
    orep(i, 0, n) {
      if (s[i] == 'V') { dp[0]++; }
      if (s[i] == '5') { dp[1] = (dp[1] + dp[0]) % mod; }
      if (s[i] == '0') { dp[2] = (dp[2] + dp[1]) % mod; }
    }
    std::cout << dp[2]; NL;
  }

  return 0;
}
