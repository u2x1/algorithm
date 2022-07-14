#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

long long s(const int n, const int k) {
  if (n<k) { return 0; }
  if (n == k || k == 1) { return 1;}
  return s(n-1,k-1) + k*s(n-1,k);
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%lld", s(n,k));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
