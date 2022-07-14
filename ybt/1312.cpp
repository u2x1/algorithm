#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

long solve[51][2];

int main() {
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int i;
  for (i = 0; i < x; ++i) {
    solve[i][0] = 1; solve[i][1] = 0;
  }
  for(; i < z+1; ++i) {
    solve[i][0] = solve[i-1][0] + solve[i-2][1]; 
    solve[i][1] = y * solve[i-x][0];
  }
  printf("%ld", solve[z][0]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
