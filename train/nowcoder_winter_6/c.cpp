#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';
const int maxN = 1e3+5;
const int m = 1e9+7;
int dp[maxN][maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> out(n+1);
  int pos = 1;
  for(int i = 1, j = n; i<=j; i++, j--) {
    out[j] = pos+1;
    out[i] = pos;
    pos+=2;
  }
  orep(i, 1, n+1) { dp[0][i] = out[i]; }
  orep(i, 1, n) {
    orep(j, 1, n-i+1) {
      dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]) % m;
    }
  }
  std::cout << dp[n-1][1]; NL;
  orep(i, 1, n+1) {
    std::cout << out[i] << " ";
  }

  return 0;
}
