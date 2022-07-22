#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int w, h;
int w_h_len;
bool walked[10][10];
int times;

void f(const int x, const int y, const int cnt) {
  if (x < 0 || y < 0 || x >= h || y >= w || walked[x][y]) { return; }
  if (cnt == w_h_len) { ++times; return; }
  walked[x][y] = 1;
  f(x+2, y+1, cnt+1); f(x+2, y-1, cnt+1);
  f(x-2, y+1, cnt+1); f(x-2, y-1, cnt+1);
  f(x-1, y+2, cnt+1); f(x+1, y+2, cnt+1);
  f(x-1, y-2, cnt+1); f(x+1, y-2, cnt+1);
  walked[x][y] = 0;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d%d%d", &h, &w, &x, &y);
    w_h_len = w*h;
    for(int i = 0; i < h; ++i) {
      for(int j = 0; j < w; ++j) {
        walked[i][j] = 0;
      }
    }
    f(x, y, 1);
    printf("%d\n", times);
    times = 0;
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
