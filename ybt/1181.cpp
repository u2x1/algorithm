#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int odd[10], even[10];

bool revCmp(int a, int b) { return a > b; }
int main() {
  int cache;
  int oddPos = -1, evenPos = -1;
  for(int i = 0; i<10; ++i) {
    scanf("%d", &cache);
    if(cache % 2) { odd[++oddPos] = cache; }
    else { even[++evenPos] = cache; }
  }
  ++oddPos; ++evenPos;

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(odd, odd+oddPos, revCmp);
  std::sort(even, even+evenPos);
  for(int i = 0; i<oddPos; ++i) {
    printf("%d ", odd[i]);
  }
  for(int i = 0; i<evenPos; ++i) {
    printf("%d ", even[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
