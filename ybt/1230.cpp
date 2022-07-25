#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>


int ys[101]; bool ex[101];
int main() {
  int n;
  scanf("%d", &n);
  int x,y;
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    if (!ex[x]) { ex[x] = 1; ys[x] = y; }
    else if (ys[x] < y) { ys[x] = y; }
  }
  int maxy = -1;
  int xss[101], yss[101], pos = -1;
  for(int i = 101; i >= 0 ; --i) {
    if (!ex[i]) { continue; }
    if (ys[i] > maxy) {
      ++pos;
      xss[pos] = i;
      yss[pos] = ys[i];
      maxy = ys[i];
    }
  }
  printf("(%d,%d)", xss[pos], yss[pos]);
  while(pos!=0) {
    --pos;
    printf(",(%d,%d)", xss[pos], yss[pos]);
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
