#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

const int maxN = 3e5+5;
int arr[maxN];
int dp[2][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int X, Y, Z; std::cin >> X >> Y >> Z;
  std::vector<std::pair<bool, int>> v;
  std::string s; std::cin >> s;
  orep(i, 0ul, s.size()) {
    int c = s[i];
    int j = i;
    for(; s[j] == c; ++j);
    v.emplace_back(c=='A', j-i);
    i = j-1;
  }
  dp[1][0] = Z;
  orep(i, 0ul, v.size()) {
    auto [x, cnt] = v[i];
    if (x == 0) {
      dp[0][i+1] = std::min({dp[0][i] + cnt * X, dp[0][i] + Z + cnt * Y + Z, dp[1][i] + cnt * Y + Z, dp[1][i] + Z + cnt * X});
      dp[1][i+1] = std::min({dp[0][i] + cnt * X + Z, dp[0][i] + Z + cnt * Y, dp[1][i] + cnt * Y, dp[1][i] + Z + cnt * X + Z});
    } else {
      std::swap(X, Y);
      dp[0][i+1] = std::min({dp[0][i] + cnt * X, dp[0][i] + Z + cnt * Y + Z, dp[1][i] + cnt * Y + Z, dp[1][i] + Z + cnt * X});
      dp[1][i+1] = std::min({dp[0][i] + cnt * X + Z, dp[0][i] + Z + cnt * Y, dp[1][i] + cnt * Y, dp[1][i] + Z + cnt * X + Z});
      std::swap(X, Y);
    }
  }
  std::cout << std::min(dp[0][v.size()], dp[1][v.size()]);

  return 0;
}
