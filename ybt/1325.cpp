#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  n = 1 << n;

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int arr[n][n] = {1};
  int s = 1;
  while(s != n) {
    for(int i = 0; i < s; ++i) {
      for(int j = 0; j < s; ++j) {
        arr[i+s][j] = arr[i][j+s]
          = arr[i][j] + s;
        arr[i+s][j+s] = arr[i][j];
      }
    }
    s<<=1;
  }
  for(int i = 0; i < s; ++i) {
    for(int j = 0; j < s; ++j) {
      printf("%d ", arr[i][j]);
    }
    putchar('\n');
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
