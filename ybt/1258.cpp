#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n+1][n+1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= i; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }
  for(int i = n-1; i != 0; --i) {
    for(int j = 1; j <= i; ++j) {
      arr[i][j] += std::max(arr[i+1][j], arr[i+1][j+1]);
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", arr[1][1]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
