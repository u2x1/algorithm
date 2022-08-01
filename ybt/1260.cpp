#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int arr[1001], len = 0;
  int dp1[1001], dp2[1001];
  int ans1=0, ans2 = 0;
  for(; ~scanf("%d", &arr[len]); ++len) {
    dp1[len] = dp2[len] = 1;
    for(int i = 0; i < len; ++i) {
      if(arr[i] >= arr[len]) {
        dp1[len] = std::max(dp1[len], dp1[i]+1);
      } else {
        dp2[len] = std::max(dp2[len], dp2[i]+1);
      }
    }
    if(dp1[len]>ans1) { ans1=dp1[len]; }
    if(dp2[len]>ans2) { ans2=dp2[len]; }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d\n%d", ans1, ans2);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
