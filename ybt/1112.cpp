#include <cstdio>
#include <climits>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int m;
  scanf("%d", &m);
  int max = INT_MIN, min = INT_MAX, cache;
  for (int i = 0; i < m && scanf("%d", &cache); ++i) {
    if (max < cache) { max = cache; }
    else if (min > cache) { min = cache; }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  printf("%d", max - min);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
