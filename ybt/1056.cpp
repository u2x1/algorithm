#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  if (x < 0) { x = -x; }
  if (y < 0) { y = -y; }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  if (x <= 1 && y <= 1) { printf("yes"); }
  else { printf("no"); }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
