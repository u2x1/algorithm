#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n]; int pos=-1; int cache;
  for(int i = 0; i<n; ++i) {
    scanf("%d", &cache);
    if(cache % 2) { arr[++pos] = cache; }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(arr, arr+pos+1);
  printf("%d", arr[0]);
  for(int i = 1; i <= pos; ++i) {
    printf(",%d", arr[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
