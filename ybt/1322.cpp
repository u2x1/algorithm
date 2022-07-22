#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int h, k = 0;
  int hLeft[1001];
  while(scanf("%d", &h) == 1) {
    int smallestH = 999999, pos;
    for(int i = 0; i < k; ++i) {
      if (hLeft[i] >= h && hLeft[i] < smallestH) {
          smallestH = hLeft[i]; pos = i;
      }
    }
    if (smallestH == 999999) {
      hLeft[k++] = h;
    } else {
      hLeft[pos] = h;
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", k);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
