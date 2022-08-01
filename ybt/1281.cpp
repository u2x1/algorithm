#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n], dp[n];
  memset(dp, 0x1f, sizeof(dp));
  const int inf = dp[0];
  for(int i = 0; i<n && ~scanf("%d", arr+i); ++i) {
    *std::lower_bound(dp, dp+n, arr[i]) = arr[i];
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int rst = 0;
  while(dp[rst] != inf) { ++rst; }
  printf("%d", rst);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
