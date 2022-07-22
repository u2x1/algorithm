#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
bool arr[21][21];
int cnt;
int w, h, sx, sy;

void f(const int x, const int y) {
  if (x == -1 || y == -1 || x == h || y == w || !arr[x][y]) { return; }
  ++cnt; arr[x][y] = 0;
  f(x+1, y);
  f(x-1, y);
  f(x, y+1);
  f(x, y-1);
}

char tmp;
void input() {
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < w; ++j) {
      while ((tmp = getchar()) == ' ' || tmp == '\n' || tmp == EOF);
      if (tmp == '.') { arr[i][j] = 1; }
      else if (tmp == '@') { arr[i][j] = 1; sx = i; sy = j; }
      else { arr[i][j] = 0; }
    }
  }
}

int main() {
  while(1) {
    scanf("%d%d", &w, &h);
    if (w == 0 && h == 0) { break; }
    input();
    f(sx,sy);
    printf("%d\n", cnt);
    cnt = 0;
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
