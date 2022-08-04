#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  double x;
  scanf("%lf", &x);
  double y;
  if (x >= 0 && x < 5) { y = 2.5 - x; }
  else if (x >= 5 && x < 10) { y = 2.0 - 1.5*(x-3)*(x-3); }
  else if (x >= 10 && x < 20) { y = x/2.0 - 1.5; }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%.3f", y);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
