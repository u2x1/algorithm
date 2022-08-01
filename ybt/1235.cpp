#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n, k;
  scanf("%d", &n);
  int arr[n];
  for(int i=0; i<n && 1==scanf("%d", &arr[i]); ++i);
  scanf("%d", &k);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::partial_sort(arr, arr+k, arr+n, [](int a, int b) { return a > b; });
  for(int i=0; i<k;++i) {
    printf("%d\n", arr[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
