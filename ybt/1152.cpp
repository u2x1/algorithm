#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

double max(double a, double b, double c) {
  double ret;
  ret = a > b ? a : b;
  ret = ret > c ? ret : c;
  return ret;
}

int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%.3f", max(a,b,c) / (max(a+b,b,c) * max(a,b,b+c)));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
