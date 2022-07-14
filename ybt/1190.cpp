#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  long rst[80] = {0};
  rst[1] = 1; rst[2] = 2; rst[3] = 4;
  int pos = 3;
  int n;
  while(scanf("%d", &n) != EOF && n != 0) {
    if (rst[n] != 0) { printf("%ld\n", rst[n]); continue; }
    for(; pos <= n && rst[pos] != 0; ++pos);
    for(; pos <= n; ++pos) { rst[pos] = rst[pos-1]+rst[pos-2]+rst[pos-3]; }
    printf("%ld\n", rst[n]);
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
