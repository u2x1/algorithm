#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int n, k;
bool putable[8][8];
int cnt;
bool row[8], col[8];

void f(const int x, const int y, const int putCnt) {
  if (putCnt == k) { ++cnt; return; }
  int j = y;
  for(int i = x; i<n; ++i) {
    while(1) {
      if (putable[i][j] && !row[i] && !col[j]) {
        row[i] = col[j] = 1;
        f(i, j, putCnt+1);
        row[i] = col[j] = 0;
      }
      if (++j == n) { j=0; break; }
    }
  }
}

void input() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if (getchar() == '#') { putable[i][j] = 1; }
      else { putable[i][j] = 0; }
    } getchar();
  }
}

int main() {
  while(1) {
    scanf("%d%d", &n, &k); getchar();
    if (n == -1 && k == -1) { break; }
    input();
//    printf("\n----\nn: %d, k: %d\n", n, k);
//    for(int i = 0; i<n; ++i){
//    for(int j = 0; j<n; ++j) {
//      putchar(putable[i][j] + '0');}
//    putchar('\n');
//    }

    f(0, 0, 0);
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
