#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  scanf("%

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
