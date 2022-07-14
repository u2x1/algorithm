#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int exist[1001];
int main() {
  int n;
  scanf("%d", &n);
  int arr[n]; int pos = -1; int cache;
  for(int i = 0; i<n;++i) {
    scanf("%d", &cache);
    if(!exist[cache]) {
      exist[cache] = 1;
      arr[++pos] = cache;
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  ++pos;
  std::sort(arr, arr+pos);
  printf("%d\n", pos);
  for(int i = 0; i < pos; ++i) {
    printf("%d ", arr[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
