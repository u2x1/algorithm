#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int dp[n+1][2] = {0};
  dp[1][0] = 1; dp[1][1] = 1;
  for(int i=2; i<=n; ++i) {
    dp[i][0] = dp[i-1][0] + dp[i-1][1] * 2;
    dp[i][1] = dp[i-1][0] + dp[i-1][1];
  }
  printf("%d", dp[n][0]+dp[n][1]+dp[n][1]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
