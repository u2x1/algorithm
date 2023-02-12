#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 5e3;
const int magic = 1e8;
int mp[13];
int dp[13][maxN];
int a[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int m, n; std::cin >> m >> n;
  orep(i, 0, m) {
    orep(j, 0, n) {
      int tmp; std::cin >> tmp;
      mp[i] = (mp[i] << 1) | !tmp;
    }
  }
  int cnt = 0;
  orep(i, 0, 1<<n) {
    if (i & (i<<1)) { continue; }
    a[cnt++] = i;
  }

  orep(i, 0, m) {
    if (!i) {
      orep(j, 0, cnt) {
        if (mp[i] & a[j]) { continue; }
        dp[i][j]++;
      }
    } else {
      orep(k2, 0, cnt) {
        if(mp[i-1] & a[k2]) { continue; }
        orep(j, 0, cnt) {
          if (mp[i] & a[j] || a[j] & a[k2]) { continue; }
          dp[i][j] += dp[i-1][k2];
          dp[i][j] %= magic;
        }
      }
    }
  }

  int ret = 0;
  orep(i, 0, cnt) {
    ret = (ret + dp[m-1][i]) % magic;
  }
  std::cout << ret;

  return 0;
}
