#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i<n && scanf("%d", &arr[i]); ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////
  int cnt = 0, tmp;
  bool flag;
  while(1) {
    flag = 0;
    for(int i = 0; i < n-1; ++i) {
      if(arr[i] > arr[i+1]) {
        ++cnt; tmp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = tmp;
        flag = 1;
      }
    }
    if (!flag) { break; }
  }
  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
