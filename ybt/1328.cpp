#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int arr[10001], tmp[10001];
int cnt;
void msort(const int l, const int r) {
  if (r - l <= 1) { return; } 
  const int mid = l + ((r-l)>>1);
  msort(l, mid);
  msort(mid, r);
  for(int i=l, j=mid, k=l; k!=r; ++k) {
    if(j==r || (i<mid && arr[i] <= arr[j])) {
        tmp[k] = arr[i++]; }
    else { tmp[k] = arr[j++]; cnt += (mid-i); }
  }
  for(int i = l; i < r; ++i) { arr[i] = tmp[i]; }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n && scanf("%d", &arr[i]) == 1; ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  msort(0, n);
  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
