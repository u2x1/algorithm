#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int arr[n+1];
  for(int i = 1; i<=n;++i) {
    scanf("%d", &arr[i]);
    arr[i] %= k;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  bool dp[n+1][k] = {0};
  dp[0][0] = 1;
  for(int i=1;i<=n;++i) {
    for(int j=0;j<k;++j) {
      dp[i][j] = dp[i-1][(k+j+arr[i])%k]
              || dp[i-1][(k+j-arr[i])%k];
    }
  }
  if(dp[n][0]) { printf("YES"); }
  else { printf("NO"); }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
