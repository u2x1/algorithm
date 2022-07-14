#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int toDml(int x, int encoding) {
  int ret = 0;
  int n = 1;
  while(x != 0) {
    ret += x % 10 * n;
    x /= 10;
    n *= encoding;
  }
  return ret;
}

int main() {
  int p, q, r;
  scanf("%d%d%d", &p, &q, &r);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for (int i = 2; i <= r ; ++i) {
    if(toDml(p,i) * toDml(q,i) == toDml(r,i)) {
      printf("%d", i);
      return 0;
    }
  }
  printf("0");

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
