#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
  int m, n, k;
  scanf("%d%d%d", &m, &n, &k);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int dp[m+1][n+1];
  memset(dp, 0x1f, sizeof(dp));
  dp[0][0] = 0;
  int a, b, w;
  for(int i=0; i<k; ++i) {
    scanf("%d%d%d", &a, &b, &w);
    for(int mj=m; mj>=0; --mj) {
      for(int nj=n; nj>=0; --nj) {
        const int u = std::min(mj+a, m)
                , v = std::min(nj+b, n);
        if (dp[u][v] > dp[mj][nj] + w) {
          dp[u][v] = dp[mj][nj] + w;
        }

      }
    }
  }
//  for(int i=0; i<=m; ++i) {
//    for(int j=0; j<=n; ++j) {
//      printf("%d ", dp[i][j] > 999 ? 999 : dp[i][j]);
//    } putchar(10);
//  }
  printf("%d", dp[m][n]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
