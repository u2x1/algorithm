#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int rst[10000][10000];

int akm(const int m, const int n) {
  int ret;
  if ((ret = rst[m][n]) != 0) { return ret; }
  if (m == 0) { rst[m][n] = (ret = n+1); return ret; }
  else if (m > 0 && n == 0) { rst[m][n] = (ret = akm(m-1, 1)); return ret; }
  rst[m][n] = (ret = akm(m-1, akm(m, n-1))); return ret;
}

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", akm(m, n));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
