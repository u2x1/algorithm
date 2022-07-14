#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int reverse(int n, int &depth) {
  if (n < 10) { return n; }
  int currDepth = depth;
  depth *= 10;
  int rst = reverse(n/10, depth);
  return (n%10) * (depth / currDepth) + rst;
}

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int depth = 1;
  printf("%d", reverse(n, depth));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
