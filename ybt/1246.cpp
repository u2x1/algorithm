#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

int main() {
  double len, n, c;
  scanf("%lf%lf%lf", &len, &n, &c);
  const double nl = (1+n*c)*len;

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  double l = 0, r = M_PI/2, mid = (l+r) / 2;
  while(r-l > 1e-12) {
    const double tmp = 2*(nl/(mid*2)) * sin(mid);
    if (tmp > len) { l=mid; }
    else { r=mid; }
    mid = (l+r)/2;
  }
  printf("%.3f", (nl/(mid*2))*(1-cos(mid)));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
