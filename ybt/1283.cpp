#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n], dpUp[n]={0}, dpDn[n]={0};
  for(int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    const int tmp = arr[i];
    dpUp[i] = dpDn[i] = 1;
    for(int j = 0; j < n; ++j) {
      if (arr[j] < tmp) {
        if (dpUp[i] < dpUp[j]+1) { dpUp[i] = dpUp[j]+1; }
      }
    }
  }
  for(int i = n-1; i!=-1; --i) {
    for(int j = n-1; j!=i; --j) {
      if (arr[j] < arr[i]) {
        if (dpDn[i] < dpDn[j]+1) { dpDn[i] = dpDn[j]+1; }
      }
    }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int max = 0;
  for(int i = 0; i<n; ++i) {
    if (max < dpUp[i]+dpDn[i]) { max = dpUp[i]+dpDn[i]; }
  }
  printf("%d", max-1);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
