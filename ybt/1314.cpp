#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

bool forbid[21][21];
long long a[21][21];
int main() {
  int n, m, cx, cy;
  scanf("%d%d%d%d", &n, &m, &cx, &cy);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  forbid[cx][cy] = 1;
  if (cy-2 > -1) {
    if (cx - 1 > -1) { forbid[cx-1][cy-2] = 1; }
    if (cx + 1 <= n+1) { forbid[cx+1][cy-2] = 1; }
  }
  if (cy+2 <= m+1) {
    if (cx - 1 > -1) { forbid[cx-1][cy+2] = 1; }
    if (cx + 1 <= n+1) { forbid[cx+1][cy+2] = 1; }
  }
  if (cx-2 > -1) {
    if (cy - 1 > -1) { forbid[cx-2][cy-1] = 1; }
    if (cy + 1 <= m+1) { forbid[cx-2][cy+1] = 1; }
  }
  if (cx+2 <= n+1) {
    if (cy - 1 > -1) { forbid[cx+2][cy-1] = 1; }
    if (cy + 1 <= m+1) { forbid[cx+2][cy+1] = 1; }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (forbid[i][j]) { a[i][j] = 0; }
      else if (i == 0 && j == 0) { a[0][0] = 1; }
      else if (i == 0) { a[0][j] = a[0][j-1];  }
      else if (j == 0) { a[i][0] = a[i-1][0]; }
      else { a[i][j] = a[i-1][j]+a[i][j-1]; }
    }
  }
  printf("%lld", a[n][m]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
