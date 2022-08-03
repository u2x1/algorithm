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

  int dp[m+1]={};
  int w,v,p;
  for(int i=0; i<n; ++i) {
    scanf("%d%d%d", &w, &v, &p);
    if (!p) {
      for(int j=w; j<=m; ++j) {
        if (dp[j] < dp[j-w] + v) {
          dp[j] = dp[j-w] + v;
        }
      }
    } else {
      while(p--) {
        for(int j=m; j>=w; --j) {
          if (dp[j] < dp[j-w] + v) {
            dp[j] = dp[j-w] + v;
          }
        }
      }
    }
  }
  printf("%d", dp[m]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
