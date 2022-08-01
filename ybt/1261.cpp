#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int dp[n+1] = {0}, sl[n+1];
  int tmp;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      scanf("%d", &tmp);
      if (!tmp) { continue; }
      if (!dp[j] || (dp[j] > (tmp+dp[i]))) { dp[j] = tmp+dp[i]; sl[j] = i; }
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////
  
  int out[n+1] = {n}, pos=1, last=n;
  while(last != 1) {
    last = (out[pos++] = sl[last]);
  }
  printf("minlong=%d\n", dp[n]);
  for(--pos; pos != -1; --pos) { printf("%d ", out[pos]); }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
