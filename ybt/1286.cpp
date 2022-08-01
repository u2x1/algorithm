#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int arr[n]; int dpUp[n], dpDn[n];
    memset(dpUp, 0, sizeof(dpUp));
    memset(dpDn, 0, sizeof(dpDn));
    int tmp;
    int maxUp=0, maxDn=0;
    for(int i = 0; i < n; ++i) {
      scanf("%d", &tmp);
      arr[i] = tmp;
      for(int j = 0; j < i; ++j) {
        if (arr[j] < tmp && dpUp[i] < dpUp[j] + 1) {
          dpUp[i] = dpUp[j] + 1; if (maxUp < dpUp[i]) { maxUp = dpUp[i]; }
        } else if (arr[j] > tmp && dpDn[i] < dpDn[j] + 1) {
          dpDn[i] = dpDn[j] + 1; if (maxDn < dpDn[i]) { maxDn = dpDn[i]; }
        }
      }
    }
    const int rst = 1 + (maxUp > maxDn ? maxUp : maxDn);
    printf("%d\n", rst);
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
