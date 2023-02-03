#include <iostream>
#include <iomanip>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e3+5;
double dp[maxN][maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int w, b;
  std::cout << std::setprecision(15);
  std::cin >> w >> b;
  orep(i, 1, w+1) { dp[i][0] = 1; }
  orep(i, 1, b+1) { dp[0][i] = 0; }
  orep(i, 1, w+1) {
    orep(j, 1, b+1) {
      dp[i][j] = 1.0*i/(i+j);
      dp[i][j] += j<3      ? 0 : 1.0*j/(i+j) * 1.0*(j-1)/(i+j-1) * 1.0*(j-2)/(i+j-2) * dp[i][j-3];
      dp[i][j] += i<1||j<2 ? 0 : 1.0*j/(i+j) * 1.0*(j-1)/(i+j-1) * 1.0*i/(i+j-2) * dp[i-1][j-2];
    }
  }
  std::cout << dp[w][b];

  return 0;
}
