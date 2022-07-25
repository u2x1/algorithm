#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int arr[m] = {0}; int tmp;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    *(std::min_element(arr, arr+m)) += tmp;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", *std::max_element(arr,arr+m));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
