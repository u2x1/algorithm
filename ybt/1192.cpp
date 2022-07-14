#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int dp[11][11] = {0};
  for(int i=0; i<11; ++i) {
    for(int j=0; j<11; ++j) {
      if(i<=1 || j<=1) { dp[i][j] = 1; }
      else if(i<j) { dp[i][j] = dp[i][i];}
      else { dp[i][j] = dp[i][j-1] + dp[i-j][j]; }
    }
  }
  int m, n2;
  for(int i=0; i<n && scanf("%d%d", &m, &n2); ++i) {
    printf("%d\n", dp[m][n2]);
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
