#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int m, n, t;
  scanf("%d%d%d", &m, &n, &t);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int ws[t+1][31], vs[t+1][31], grpCnt[t+1] = {};
  int w, v, p;
  for(int i=0; i<n; ++i) {
    scanf("%d%d%d", &w, &v, &p);
    ws[p][grpCnt[p]]   = w;
    vs[p][grpCnt[p]] = v;
    grpCnt[p]++;
  }

  int dp[m+1]={};
  for(int i=1; i<=t; ++i) {
    for(int k=m; k >= 0; --k) {
      for(int j=0; j<grpCnt[i]; ++j) {
        if (k < ws[i][j]) { continue; }
        dp[k] = std::max(dp[k], dp[k-ws[i][j]] + vs[i][j]);
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
