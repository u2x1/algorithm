#include <iostream>
#include <cstring>
#include <vector>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
const int mod = 998244353;
int arr[maxN];
const std::string cs = " nunhehheh";

long long two[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  two[0] = 1;
  orep(i, 1, maxN) { two[i] = two[i-1] * 2 % mod; }
  int t; std::cin >> t;
  while(t--) {
    std::string s; std::cin >> s; s = " " + s;
    std::vector<int> as(s.size(), 0);
    std::vector<long long> dp(9, 0); dp[0] = 1;
    orep(i, 1ul, s.size()) {
      as[i] = (s[i] == 'a') + as[i-1];
    }
    int ret = 0;
    orep(i, 1ul, s.size()) {
      if (s[i] == 'h') {
        ret = (ret+dp[cs.size()-2]*(-1+two[as[s.size()-1] - as[i]])%mod) % mod;
      }
      for(int j = cs.size()-2; j > 0; --j) {
        if (s[i] == cs[j]) { dp[j] += dp[j-1]; dp[j] %= mod; }
      }
    }
    std::cout << ret % mod; NL;
  }

  return 0;
}
