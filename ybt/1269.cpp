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
    while(s--) {
      for(j=m; j>=w; --j) {
      if (dp[j] < dp[j-w] + v) {
          dp[j] = dp[j-w] + v;
          if (max < dp[j]) { max = dp[j]; }
        }
//        printf("%d %d %d dp[%d]=%d\n", w, v, s, j, dp[j]);
      }
    }
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
