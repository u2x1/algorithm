#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

int f(int n, int start) {
  int boundary = sqrt(n) + 0.5;
  int ret = 1;
  for(int i = start; i <= boundary; ++i) {
    if (n % i == 0) {
      ret += f(n/i, i);
    }
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  int x;
  for(int i = 0; i<n && scanf("%d", &x); ++i) {
    printf("%d\n", f(x, 2));
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
