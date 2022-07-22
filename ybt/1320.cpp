#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int n, avg;
int arr[101];


int main() {
  scanf("%d", &n);
  int sum = 0;
  for(int i=0; i<n; ++i) {
    scanf("%d", &arr[i]);
    sum+=arr[i];
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  avg = sum / n;
  int cnt = 0;
  for(int i=1; i<n; ++i) {
    if(arr[i-1] == avg) { continue; }
    arr[i] -= avg - arr[i-1];
    //arr[i-1] = avg;
    ++cnt;
  }
  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
