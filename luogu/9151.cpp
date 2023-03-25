#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 5e6+5;
int arr[maxN];
int dp[maxN][2][2];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::string s; std::cin >> s;
    const auto n = s.size();
    // dp[0][]
    orep(i, 0ul, n) {
      if (s[i] == '1') {
        dp[i][1][0] = dp[i-1][0][0]
      }
      dp[i][]
    }
  }

  return 0;
}
