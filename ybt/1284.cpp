#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>
#include <cstring>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n+1][m+1];
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(int)*(m+1)*(n+1));
    memset(arr, 0, sizeof(int)*(m+1)*(n+1));
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        scanf("%d", &arr[i][j]);
      }
    }
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        dp[i][j] = arr[i][j] + std::max(dp[i-1][j], dp[i][j-1]);
      }
    }
    printf("%d\n", dp[n][m]);
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
