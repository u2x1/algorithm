#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int f(int m, int n) {
  if (m == 0 || n == 1) { return 1; }
  if (n == 0) { return 0; }
  if (m < n) { return f(m, m); }
  return f(m, n-1) + f(m-n, n);
}

int main() {
  int n;
  scanf("%d", &n);
  int a, b;
  for(int i = 0; i < n && scanf("%d%d", &a, &b); ++i) {
    printf("%d\n", f(a,b));
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
