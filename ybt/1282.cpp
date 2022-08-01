#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n+1][n+1], tmp;
  memset(arr, 0, (n+1)*(n+1)*sizeof(int));
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      scanf("%d", &tmp);
      arr[i][j] = arr[i][j-1] + tmp;
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int max = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j <= n; ++j) {
      int curSum = 0;
      for(int r = 1; r <= n; ++r) {
        curSum += arr[r][j] - arr[r][i];
        if (max < curSum) { max = curSum; }
        if (curSum < 0) { curSum = 0; }
      }
    }
  }
  printf("%d", max);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
