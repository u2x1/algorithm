#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

bool isComplete(int i) {
  int root = sqrt(i) + 0.5;
  int sum = 1;
  for (int j = 2; j <= root; ++j) {
    if (i % j == 0) {
      sum += j + i/j;

    }
  }
  if (sum == i) { return true; }
  else { return false; }
}

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for (int i = 3; i <= n; ++i) {
    if (isComplete(i)) {
      printf("%d\n", i);
    }
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
