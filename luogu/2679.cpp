#include <iostream>
#include <cstring>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e3+5;
const int mod = 1e9+7;
int dp[maxN][205][2];
int sum[maxN][205][2];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, z; std::cin >> n >> m >> z;
  std::string a, b; std::cin >> a >> b;

  bool r = 0;
  orep(i, 0, n+1) {
    sum[i][0][0] = dp[i][0][0] = 1;
  }

  orep(i, 0, n) {
    orep(j, 0, m) {
      if (a[i] == b[j]) {
        sum[i+1][j+1][0] += sum[i][j][0];
      }
    }
  }

  orep(k, 0, z) {
    r = !r;

    orep(i, 0, n+1) {
      orep(j, 0, m+1) {
        sum[i][j][r] = dp[i][j][r] = 0;
      }
    }

    orep(i, 1, n+1) {
      orep(j, 1, m+1) {
        sum[i][j][r] = dp[i][j][r] = dp[i-1][j][r];
        if (a[i-1] == b[j-1]) {
          dp[i][j][r] = (dp[i][j][r] + sum[i-1][j-1][!r]) % mod;
          sum[i][j][r] = (dp[i][j][r] + sum[i-1][j-1][r]) % mod;
        }
      }
    }
  }

  std::cout << dp[n][m][r];

  return 0;
}
