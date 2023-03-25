#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e3+5;
const int mod = 1e9+7;
long long dp[201][201];
long long sum[201][201];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, z; std::cin >> n >> m >> z;
  std::string a, b;
  std::cin >> a >> b;
  a = " " + a; b = " " + b;
  dp[0][0] = 1;
  orep(i, 1, n+1) {
    drep(j, m, -1) {
      orep(k, 1, j+1) {
        sum[j][k] = 0;
        if (a[i] == b[j]) {
          sum[j][k] = (sum[j-1][k] + dp[j-1][k-1]) % mod;
        }
        dp[j][k] = (dp[j][k] + sum[j][k]) % mod;
      }
    }
  }
  std::cout << dp[m][z];


  return 0;
}
