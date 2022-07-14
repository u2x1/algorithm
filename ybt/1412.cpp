#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

bool isA(int x) {
  int zero = 0, one = 0;
  while (x) {
    if (x&1) { ++one; } 
    else { ++zero; } 
    x >>= 1;
  }
  if (zero < one) { return true; }
  return false;
}

int main() {

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int aCnt = 0;
  for (int i = 1; i < 1001; ++i) {
    if (isA(i)) { ++aCnt; }
  }
  printf("%d %d", aCnt, 1000-aCnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
