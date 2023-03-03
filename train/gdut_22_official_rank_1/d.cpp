#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

long long dp[30][10];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  dp[1][1] = 1; dp[1][2] = 2; dp[1][3] = 3;
  orep(j, 4, 10) { dp[1][j] = 3; }
  orep(i, 2, 30) {
    orep(j, 1, 10) {
      if (j > 4) { dp[i][j] = dp[i][4]; }
      else { dp[i][j] = dp[i][j-1] + dp[i-1][4]; }
      // std::cout << "dp " << i << " " << j << ": " << dp[i][j]; NL;
    }
  }

  std::string s; std::cin >> s;
  while(s[0] == '0') { s = s.substr(1); }
  unsigned long long ret = 0ull;
  for(auto i = 1ull; i <= s.size(); ++i) {
    auto pos = i-1;
    ret += dp[s.size()-pos][s[pos]-'0'];
    if (s[pos] > '3') { 
      break;
    }
  }
  std::cout << ret;

  return 0;
}
