#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  while(1) {
    int n;
    if (scanf("%d", &n) != 1) { break; }
    int arr[n], sum = 0, max = -1;
    for(int i = 0; i < n && scanf("%d", &arr[i]) == 1 ; ++i) {
      sum += arr[i];
      max = arr[i] > max ? arr[i] : max;
    }
    if (max >= sum-max) {
      printf("%.1f\n", 1.0*sum-max);
    } else {
      printf("%.1f\n", sum*1.0/2);
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
