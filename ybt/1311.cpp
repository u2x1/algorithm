#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#define DEBUG printf("[%s] at ln%d\n", __FUNCTION__, __LINE__);
#define PT(var, d) printf(#var": %"#d" ", var);
#define NL printf("\n");
#include <cstdio>

int n, arr[100001], tmp[100001];
long long cnt = 0;

void msort(int l, int r) {
  if (r - l < 2) { return; }
  int mid = l + ((r-l)>>1);
  msort(l, mid); msort(mid, r);
  int lPos = l, rPos = mid;
  for(int i = l; i < r; ++i) {
    if (lPos >= mid || (rPos < r && arr[lPos] > arr[rPos])) {
      tmp[i] = arr[rPos++];
      cnt += mid-lPos;
    } else {
      tmp[i] = arr[lPos++];
    }
  }
  for (int i = l; i < r; ++i) { arr[i] = tmp[i]; }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n && scanf("%d", &arr[i]) != EOF; ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  msort(0, n);
  printf("%lld", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
