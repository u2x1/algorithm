#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int r[n][2] = {0};
  r[0][0] = 9; r[0][1] = 1; // 0 even, 1 odd
  for(int i = 1; i < n-1; ++i) {
    r[i][0] = (9*r[i-1][0] + r[i-1][1]) % 12345;
    r[i][1] = (r[i-1][0] + 9*r[i-1][1]) % 12345;
  }
  r[n-1][0] = (8*r[n-2][0] + r[n-2][1]) % 12345;  // can't start with 0
  printf("%d", r[n-1][0]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
