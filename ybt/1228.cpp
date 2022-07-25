#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n; long b;
  scanf("%d%ld", &n, &b);
  int arr[n];
  for(int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  std::sort(arr, arr+n);
  int cnt = 0;
  for(int i = n-1; i != -1; --i) {
    if (b < 0) {
      break;
    }
    b -= arr[i];
    ++cnt;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
