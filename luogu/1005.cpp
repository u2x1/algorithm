#include <iostream>
#include <algorithm>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 80+5;

__int128 arr[maxN][maxN];
__int128 dp[maxN][maxN];

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}

__int128 twos[129];

int main() {
  int n =read(), m=read();

  orep(i, 0, n) {
    orep(j, 0, m) {
      arr[i][j] = read();
    }
  }

  twos[0] = 1;
  orep(i, 1, 129) {
    twos[i] = twos[i-1] << 1;
  }

  __int128 ret = 0;
  orep(i, 0, n) {
    memset(dp, 0ll, sizeof(dp));
    orep(j, 0, m) { dp[j][j] = arr[i][j]*(twos[m]); }
    orep(k, 1, m+1) {
      for(int j = 0; j < m && j+k < m; ++j) {
        dp[j][j+k] = std::max(arr[i][j] * twos[m-k] + dp[j+1][j+k]
                            , arr[i][j+k] * twos[m-k] + dp[j][j+k-1]);
      }
    }
    ret = dp[0][m-1] + ret;
  }
  print(ret);

  return 0;
}
