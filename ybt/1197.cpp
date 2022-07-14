#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////
#include <cstdio>

#define MIN(a,b) (((a)<(b))?(a):(b))

int main() {
  int m,n;
  scanf("%d%d", &m, &n);
  int dist[m+2][m+2] = {0};
  for(int i=1;i<m;++i) {
    scanf("%d", &dist[i][i+1]);
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for(int i=1;i<=m;++i) {
    for(int j=i+1;j<=m;++j) {
      dist[i][j] = dist[j][i]
        = dist[i][j-1] + dist[j-1][j];
    }
  }
  int schDist[m+2][m+2] = {0}, mid;
  for(int i=1; i<=m; ++i) {
    for(int j=i+1; j<=m; ++j) {
      mid = (i+j)/2;
      for(int k=i; k <= j;++k) {
        schDist[i][j] += dist[k][mid]; }
    }
  }
  int dp[m+1][n+1] = {0};
  for(int i=2;i<=m;++i) {
    dp[i][1] = schDist[1][i]; }
  for(int i=1;i<=m;++i){
    for(int j=2;j<=n;++j){
      dp[i][j] = 999999;
      for(int k=j-1;k<=i;++k) {
        dp[i][j] = MIN(dp[i][j], dp[k][j-1]+schDist[k+1][i]); }
    }
  }
  printf("%d", dp[m][n]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
