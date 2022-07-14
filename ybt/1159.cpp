#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int fib(int n, const int *fibs, const int len) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  if (fibs[n]) { return fibs[n]; }
  return (fib(n-1, fibs, len) + fib(n-2, fibs, len));
}


int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int fibs[n+1]; memset(fibs, 0, sizeof(fibs));
  printf("%d", fib(n-1, fibs, n+1));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
