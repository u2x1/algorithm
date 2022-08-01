#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  long long b_raw, p_raw, k_raw;
  scanf("%lld%lld%lld", &b_raw, &p_raw, &k_raw);
  long long b = b_raw, p = p_raw, k = k_raw;

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  b %= k;
  long long rst = 1, cur = b;
  while(p >= 2) {
    if (p % 2) { rst = (rst*cur)%k; --p; }
    cur = (cur*cur) % k;
    p /= 2;
  }
  // if (p == 2) { rst *= cur * cur; }
  if (p == 1) { rst *= cur; }
  rst %= k;
  printf("%lld^%lld mod %lld=%lld", b_raw, p_raw, k_raw, rst);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
