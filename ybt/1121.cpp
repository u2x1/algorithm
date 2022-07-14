#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  int cache, sum = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &cache);
      if (i == 0 || j == 0 || i == m-1 || j == n-1) {
        sum += cache;
      }
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  printf("%d", sum);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
