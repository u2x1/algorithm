#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n], dp[n] = {0};
  int tmp;
  int max=0, maxpos = 0;
  for(int i=0; i<n && ~scanf("%d", &tmp); ++i) {
    for(int j=0; j<i; ++j) {
      if (tmp >= arr[j]) { dp[i] = std::max(dp[i], dp[j]+1); }
    }
    if (dp[i] > max) { max=dp[i]; maxpos=i; }
    arr[i] = tmp;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  const int max_cp = max+1;
  printf("max=%d\n", max_cp);
  int cur = 99999999;
  int out[max_cp], p = max;
  for(int i=maxpos; i!=-1 && max!=-1; --i) {
    if (dp[i] == max && arr[i] <= cur) {
      out[p--] = arr[i];
      cur = arr[i]; --max;
    }
  }
  for(int i = 0; i<max_cp; ++i) {
    printf("%d ", out[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
