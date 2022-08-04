#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  double delta = std::sqrt(b*b-4*a*c);
  if (delta < 1e-6) {
    printf("x1=x2=%.5f", (-b + delta) / (2.0*a));
  } else if (delta > 0) {
    printf("x1=%.5f;x2=%.5f"
        , (-b + delta) / (2.0*a)
        , (-b - delta) / (2.0*a));
  } else {
    printf("No answer!");
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
