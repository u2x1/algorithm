#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

void msort(int *arr, int *tmp, const int l, const int r) {
  if (r-l <= 1) { return; }
  int mid = l+((r-l)>>1);
  msort(arr, tmp, l, mid);
  msort(arr, tmp, mid, r);
  for(int i=l, j=mid, k=l; k!=r; ++k) {
    if (i==mid || (j!=r && arr[i]>arr[j]))
      { tmp[k] = arr[j++]; }
    else { tmp[k] = arr[i++]; }
  }
  for(int i=l; i<r; ++i) { arr[i] = tmp[i]; }
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n], tmp[n];
  for(int i = 0; i<n && scanf("%d", &arr[i])==1; ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  msort(arr,tmp, 0, n);
  int cur=arr[0], cnt = 1;
  for(int i = 1; i < n; ++i) {
    if (cur != arr[i]) {
      printf("%d %d\n", cur, cnt);
      cur = arr[i]; cnt = 1;
    } else { ++cnt; }
  }
  printf("%d %d\n", cur, cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
