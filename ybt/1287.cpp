#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n+1][n+1];
  for(int i = 0; i<n; ++i) {
    for(int j = 0; j<n; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for(int i = 1; i<n; ++i) {
    arr[0][i] += arr[0][i-1];
    arr[i][0] += arr[i-1][0];
  }
  for(int i = 1; i<n; ++i) {
    for(int j = 1; j<n; ++j) {
      arr[i][j] += std::min(arr[i-1][j], arr[i][j-1]);
    }
  }
  printf("%d", arr[n-1][n-1]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
