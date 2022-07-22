#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <stdio.h>

int n; bool arr[101][101]; int sx, sy, tx, ty;
bool walked[101][101];

char tmp;
void input() {
  scanf("%d", &n); getchar();
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if (getchar() == '#') { arr[i][j] = 1; }
      else { arr[i][j] = 0; }
      if (walked[i][j]) { walked[i][j] = 0; }
    }
    getchar();
  }
  scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
}

bool check(const int x, const int y) {
  if (x == n || y == n || x < 0 || y < 0) { return false; }
  if (walked[x][y] || arr[x][y]) { return false; }
  if (x == tx && y == ty) { return true; }
  walked[x][y] = 1;
  if (check(x+1, y) || check(x-1, y) || check(x, y+1) || check(x, y-1)) {
    return true;
  }
  return false;
}

void f() {
  if (check(sx, sy)) { printf("YES\n"); }
  else { printf("NO\n"); }
}

int main() {
  int k;
  scanf("%d", &k);
  for(int i = 0; i < k; ++i) { input(); f(); }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
