#include <iostream>
#include <string>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
int dp[51][51];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string a, b;
  std::cin >> a >> b;
  orep(i, 0ul, a.size()) {
    orep(j, 0ul, b.size()) {
      dp[i+1][j+1] = dp[i][j] + (a[i] == b[j] ? 2 : 0);
      orep(k, 1ul, i+1) { dp[i+1][j+1] = std::max(dp[i+1][j+1], dp[k][j+1]-1); }
      orep(k, 1ul, j+1) { dp[i+1][j+1] = std::max(dp[i+1][j+1], dp[i+1][k]-1); }
    }
  }
  std::cout << dp[a.size()][b.size()];


  return 0;
}
