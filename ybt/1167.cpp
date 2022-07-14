#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

double f(const double x, const int n) {
  if (n == 1) { return x/(1+x); }
  return x/(n+f(x,n-1));
}

int main() {
  double x; int n;
  scanf("%lf%d", &x, &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%.2f", f(x,n));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
