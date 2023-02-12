#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e3+5;
long long a[maxN], dp[10][maxN][maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;

  int cnt = 0;
  orep(i, 0, 1<<n) {
    if ((i<<1)&i) { continue; }
    a[cnt++] = i;
  }

  orep(i, 0, n) {
    if (!i) {
      orep(j, 0, cnt) {
        dp[i][j][__builtin_popcount(a[j])]++;
      }
    } else {
      orep(k1, 0, cnt) {
        orep(j, 0, cnt) {
          if (a[k1] & a[j] || (a[k1] << 1) & a[j] || a[k1] & (a[j] << 1)) { continue; }
          int contri = __builtin_popcount(a[j]);
          for(int p = k; p >= contri; --p) {
            dp[i][j][p] += dp[i-1][k1][p-contri];
          }
        }
      }
    }
  }
  long long ret = 0;
  orep(i, 0, cnt) {
    ret += dp[n-1][i][k];
  }
  std::cout << ret;

  return 0;
}
