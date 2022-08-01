#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n], max[n] = {0};
  int rst = 0;
  for(int i=0; i<n; ++i) {
    scanf("%d", &arr[i]);
    const int tmp = arr[i];
    max[i] = tmp;
    for(int j=0; j<i; ++j) {
      if (arr[j] < tmp) {
        if (max[j] + tmp > max[i]) { max[i] = max[j]+tmp; }
      }
    }
    if (rst < max[i]) { rst = max[i]; }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", rst);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
