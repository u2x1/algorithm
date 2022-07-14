#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int f(int x) {
  if (x == 1) { return 1; }
  if (x == 2) { return 2; }
  return f(x-1) + f(x-2);
}

int main() {
  int x;
  while (scanf("%d", &x) == 1) {
    printf("%d\n", f(x));
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
