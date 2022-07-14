#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int ans[1000001] = {0, 1, 2};

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 3; i<1000001; ++i) {
    ans[i] = (2*ans[i-1] + ans[i-2])%32767;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////
  
  int tmp;
  for(int i = 0; i<n && scanf("%d", &tmp); ++i) {
    printf("%d\n", ans[tmp]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
