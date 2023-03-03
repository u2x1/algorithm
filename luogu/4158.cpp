#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 55;
const int maxT = 2501;
std::string arr[maxN];
int dp[maxN][maxN][maxT][2];
int maxdp[maxT];
int pack[maxT];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, t; std::cin >> n >> m >> t;
  orep(i, 0, n) {
    std::cin >> arr[i];
  }
  orep(i, 0, n) {
    orep(j, 0, m) {
      orep(k, 1, m+1) {
        dp[i][j+1][k][0] = (arr[i][j] == '0') + std::max(dp[i][j][k-1][1], dp[i][j][k][0]);
        dp[i][j+1][k][1] = (arr[i][j] == '1') + std::max(dp[i][j][k-1][0], dp[i][j][k][1]);
      }
    }
    orep(k, 1, m+1) {
      maxdp[k] = 0;
      maxdp[k] = std::max(dp[i][m][k][0], dp[i][m][k][1]);
    }
    for(int k = t; k > 0; k--) {
      for(int j = 1; j <= m && k-j >= 0; j++) {
        pack[k] = std::max(pack[k], pack[k-j] + maxdp[j]);
      }
    }
  }

  std::cout << pack[t];

  return 0;
}
