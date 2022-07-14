#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  bool arr1[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &arr1[i][j]);
    }
  }
  int sum = 0, cache;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &cache);
      if (cache == arr1[i][j]) { ++sum; }
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif
  

  printf("%.2f", 100.0*sum/(m*n));

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
