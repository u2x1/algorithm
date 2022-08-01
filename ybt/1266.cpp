#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int arr[n+1][m+1]; memset(arr, 0, sizeof(int)*(m+1)*(n+1));
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int dp[n+1][m+1]; memset(dp, 0, sizeof(int)*(m+1)*(n+1));
  int sl[n+1][m+1]; memset(sl, 0, sizeof(int)*(m+1)*(n+1));

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      for(int k=0; k<=j; ++k) {
        const int newone = dp[i-1][k] + arr[i][j-k];
        if (newone > dp[i][j]) {
          dp[i][j] = newone;
          sl[i][j] = j-k;
        }
      }
    }
  }
  printf("%d", dp[n][m]);
  int rst[n+1]; const int n_cp = n+1;
  while(n != 0 && m>-1) {
    rst[n] = sl[n][m];
    m -= sl[n][m];
    --n;
  }
  for(int i = 1; i<n_cp; ++i) {
    printf("\n%d %d", i, rst[i]);
  }


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
