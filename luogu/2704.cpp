#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e2+5;
const int stateMaxN = 1 << 10;
int a[stateMaxN], cnt, dp[maxN][stateMaxN][stateMaxN];
int mp[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  char c;
  orep(i, 0, n) {
    orep(j, 0, m) {
      std::cin >> c;
      mp[i] = (mp[i] << 1) | (c == 'H');
    }
  }
  orep(i, 0, 1<<m) {
    if (((i << 2) & i) || ((i << 1) & i)) { continue; }
    a[cnt++] = i;
  }

  orep(i, 0, n) {
    if (i == 0) {
      orep(j, 0, cnt) {
        if (a[j] & mp[0]) { continue; }
        dp[i][j][0] = __builtin_popcount(a[j]);
      }
    } else if (i == 1) {
      orep(k1, 0, cnt) {
        if (a[k1] & mp[0]) { continue; }
        orep(k2, 0, cnt) {
          if (a[k2] & mp[1]) { continue; }
          if (a[k2] & a[k1]) { continue; }
          dp[i][k2][k1] = __builtin_popcount(a[k2]) + dp[i-1][k1][0];
        }
      }
    } else {
      orep(cur, 0, cnt) {
        if (a[cur] & mp[i]) { continue; }
        orep(k1, 0, cnt) {
          if ((a[k1] & mp[i-2]) || (a[cur] & a[k1])) { continue; }
          orep(k2, 0, cnt) {
            if ((a[k2] & mp[i-1]) || (a[cur] & a[k2]) || (a[k2] & a[k1])) { continue; }
            dp[i][cur][k2] = std::max(dp[i][cur][k2]
                  , __builtin_popcount(a[cur]) + dp[i-1][k2][k1]);
          }
        }
      }
    }
  }
  int ret = 0;
  orep(i, 0, cnt) {
    orep(j, 0, cnt) {
      ret = std::max(ret, dp[n-1][i][j]);
    }
  }
  std::cout << ret;

  return 0;
}
