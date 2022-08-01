#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

bool f(double x) {
  const double x2 = x*x, x3=x2*x, x4=x3*x, x5=x4*x;
//  printf("f(%.7f): %.5f\n", x, (x5-15*x4+85*x3-225*x2+274*x-121));
  return 0 < (x5-15*x4+85*x3-225*x2+274*x-121);
}

int main() {
#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int l = 15000000, r = 24000000, mid = (l+r) >> 1;
  while(l<r-1) {
    if (f(mid/10000000.0)) { l = mid; }
    else { r = mid; }
    mid = (l+r)>>1;
  }
  printf("%.6f", mid/10000000.0);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
