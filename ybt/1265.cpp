#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
  char a[1001], b[1001];
  scanf("%s%s", a, b);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  const int alen = strlen(a), blen = strlen(b);
  int dp[alen+1][blen+1];
  memset(dp, 0, sizeof(int)*(alen+1)*(blen+1));
  for(int i = 1; i <= alen; ++i) {
    for(int j = 1; j <= blen; ++j) {
      if (a[i-1] == b[j-1]) { dp[i][j] = dp[i-1][j-1] + 1; }
      else { dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]); }
    }
  }
  printf("%d", dp[alen][blen]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
