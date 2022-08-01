#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i<n && scanf("%d", &arr[i]); ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(arr,arr+n);
  int last = arr[0];
  for(int i = 1; i < n; ++i) {
    if (arr[i] != last) { printf("%d ", last); last=arr[i]; }
  }
  printf("%d ", last);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
