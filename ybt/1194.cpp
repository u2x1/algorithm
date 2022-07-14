#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int dp[m][n];
  for(int i = 0; i < m; ++i) {dp[i][0] = 1;}
  for(int i = 0; i < n; ++i) {dp[0][i] = 1;}
  for(int i = 1; i < m; ++i) {
    for(int j = 1; j < n; ++j) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
  }
  printf("%d", dp[m-1][n-1]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
