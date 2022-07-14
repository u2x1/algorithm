#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int fibs[21];

int fib(int n) {
  if (n < 3) { return 1; }
  if (fibs[n]) { return fibs[n]; }
  return (fibs[n] = fib(n-1) + fib(n-2));
}

int main() {
  int n;
  scanf("%d", &n);
  int x;
  for(int i = 0; i<n && scanf("%d", &x); ++i) {
    printf("%d\n", fib(x));
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
