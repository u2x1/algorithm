#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

double rst[10000][10000];

double h(const int n, const int x) {
  if (n==0) { return 1;}
  if (rst[n][x]!=0) { return rst[n][x]; }
  double ret;
  if (n == 1) { rst[n][x] = (ret=2*x); return ret; }
  else { rst[n][x] = (ret=2*x*h(n-1,x)-2*(n-1)*h(n-2,x)); return ret; }
}

int main() {
  int n, x;
  scanf("%d%d", &n, &x);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%.2f", h(n, x));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
