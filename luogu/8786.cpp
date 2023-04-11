#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e2+5;
const int mod  = 1e9+7;
int arr[maxN];
long long dp[maxN][maxN][2*maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  for(int i = n; i >= 0; --i) {
    for(int j = m; j >= 0; --j) { 
      for (int k = n+m; k >= 0; --k) {
        if (i == n && j == m && k == 0) { dp[i][j][k] = 1; continue; }
        dp[i][j][k] = (j != m ? dp[i+1][j][k*2] : 0) + (k ? dp[i][j+1][k-1] : 0);
        dp[i][j][k] %= mod;
      }
    }
  }
  std::cout << dp[0][0][2];


  return 0;
}
