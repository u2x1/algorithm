#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  ++n;
  int arr[n][n] = {0};
  for(int i = 1; i < n; ++i) {
    for(int j = 1; j < n; ++j) {
      scanf("%d", &arr[i][j]);
      arr[i][j] += arr[i][j-1];
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int ret = -1;
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      int acc = 0;
      for(int r = 1; r < n; ++r) {
        acc += arr[r][j] - arr[r][i];
        // discard, this is where greedy
        if (acc > ret) { ret = acc; }
        if (acc < 0) { acc = 0; }
      }
    }
  }
  printf("%d", ret);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
