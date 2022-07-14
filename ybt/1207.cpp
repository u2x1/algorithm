#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int gcd(int a, int b) {
  if (!b) { return a; }
  return gcd(b, a%b);
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  if (a < b) { int t = a; a = b; b = t; }
  printf("%d", gcd(a, b));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
