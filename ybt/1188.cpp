#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
int fib[1000001];

int getFib(int n) {
  if (fib[n]) { return fib[n]; }
  for (int i = 3; i <= n; ++i) {
    if (fib[i]) { continue; }
    fib[i] = (fib[i-1] + fib[i-2]) % 1000;
  }
  return fib[n];
}

int main() {
  int n;
  scanf("%d", &n);
  fib[1] = 1; fib[2] = 1;
  int x;
  for(int i = 0; i < n && scanf("%d", &x); ++i) {
    printf("%d\n", getFib(x));
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
