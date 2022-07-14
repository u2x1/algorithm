#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int unhappyDay = 0, unhappyHour = 0;
  int currTotal, currClass, currExtra;
  for (int i = 0; i < 7 && scanf("%d%d", &currClass, &currExtra); ++i) {
    currTotal = currClass + currExtra;
    if (currTotal > 8 && currTotal > unhappyHour) {
      unhappyHour = currTotal;
      unhappyDay = i + 1;
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  printf("%d", unhappyDay);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
