#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

int main() {
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) { break; }
    double min = 999999;
    int a, b;
    double tmp;
    for(int i = 0; i < n; ++i) {
      scanf("%d%d", &a, &b);
      if (b < 0) { continue; }
      tmp = b + 4500*3.6 / a;
      min = tmp > min ? min : tmp;
    }
    printf("%.0f\n", ceil(min));
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
