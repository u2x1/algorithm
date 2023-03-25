#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
const int mod = 1e8;
int arr[maxN];
int dp[2][maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, f;
  std::cin >> n >> f;
  bool mode = 1;
  orep(i, 0, n) {
    mode = !mode;
    int tmp; std::cin >> tmp; tmp %= f;
    orep(j, 0, f) {
      // std::cout << (j+f-tmp)%f; NL;
      dp[mode][j] = dp[!mode][j] + dp[!mode][(j+f-tmp)%f];
      dp[mode][j] %= mod;
      // std::cout << mode << "," << f << ":" << dp[mode][j]; NL;
    }
    dp[mode][tmp]++;
    dp[mode][tmp] %= mod;
  }
  std::cout << dp[mode][0];

  return 0;
}
