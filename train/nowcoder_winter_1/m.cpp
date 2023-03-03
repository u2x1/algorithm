#include <iostream>
#include <iomanip>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 1e3+5;
int arr[maxN];
double dp[maxN][maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::cout << std::setprecision(10);
  int n, m; std::cin >> n >> m;
  orep(i, 1, n+1) {
    for(int j = m; j >= 1; j--) {
      orep(k, 0, j+1) {
        dp[i][j] = std::max(dp[i-1][j-k] + 1.0*k/j, dp[i][j]);
      }
    }
  }
  
  std::cout << dp[n][m];

  return 0;
}
