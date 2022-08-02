#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int dp[m+1]={};
  int w, v, s;
  int max = 0;
  for(int i=0; i<n; ++i) {
    scanf("%d%d%d", &w, &v, &s);
    int j;
    for(j=w; j<=m && s; ++j) {
      if (dp[j] < dp[j-w] + v) {
        dp[j] = dp[j-w] + v;
        --s;
        if (max < dp[j]) { max = dp[j]; }
      }
      printf("%d %d %d dp[%d]=%d\n", w, v, s, j, dp[j]);
    }
    for(; j <= m; ++j) { dp[j] = dp[j-1]; }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", max);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
