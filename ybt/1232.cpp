#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int x; scanf("%d", &x);
    int arr[x];
    for(int i = 0; i<x; ++i) {
      scanf("%d", &arr[i]);
    } std::sort(arr,arr+x);
    int cnt = 0;
    while(x > 3) {
      cnt += std::min(arr[0]+2*arr[1]+arr[x-1]
                    , 2*arr[0]+arr[x-1]+arr[x-2]);
      x-=2;
    }
    if (x == 3) { cnt += arr[0]+arr[1]+arr[2]; }
    if (x == 2) { cnt += arr[1]; }
    if (x == 1) { cnt += arr[0]; }
    printf("%d\n", cnt);
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
