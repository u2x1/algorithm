#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cache;
  for (int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      scanf("%d", &cache);
      if (cache != 0) {
        printf("%d %d %d\n", i+1, j+1, cache);
      }
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
