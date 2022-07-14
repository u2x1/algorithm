#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

int getFactorSum(int x) {
  int sum = 1;
  int root = sqrt(x) + 0.5;
  for (int i = 2; i <= root; ++i) {
    if (x % i == 0) {
      sum += i + x/i;
    }
  }
  return sum;
}

int main() {

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for (int i = 2; ; ++i) {
    int sum = getFactorSum(i);
    if (sum != i && getFactorSum(sum) == i) {
      printf("%d %d", i, sum);
      break;
    }
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
