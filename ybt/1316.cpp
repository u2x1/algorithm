#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
long rst[1001];
long f(const int n) {
  if (n < 0) { return 0; }
  else if (n == 1) { return 1; }
  if (rst[n]) { return rst[n]; }
  const int half = (n+0.5) / 2;
  int ret = 1;
  for(int i = 1; i <= half; ++i) {
    ret += f(i);
  }
  rst[n] = ret;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%ld", f(n));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
