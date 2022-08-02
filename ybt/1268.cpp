#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int m,n;
  scanf("%d%d", &m, &n);
  int w, v;
  int dp[m+1] = {};
  for(int i=0; i<n; ++i) {
    scanf("%d%d", &w, &v);
    for(int j=w; j<=m; ++j) {
      dp[j] = std::max(dp[j], dp[j-w] + v);
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("max=%d", dp[m]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
