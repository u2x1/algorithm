#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

double f(const double x, const int n, const int currN, const double ans) {
  if (currN > n) { return ans; }
  return f(x, n, currN+1, sqrt(currN+ans));
}

int main() {
  double x; int n;
  scanf("%lf%d", &x, &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%.2f", f(x, n, 1, x));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
