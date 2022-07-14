#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int cnt[102];

int main() {
  int n;
  scanf("%d", &n);
  int cache;
  for(int i = 0; i < n; ++i) {
    scanf("%d", &cache);
    ++cnt[cache+50];
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  n /= 2;
  for(int i = 0; i < 102; ++i) {
    if(cnt[i] > n) { printf("%d", i-50); return 0; }
  }
  printf("no");

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
