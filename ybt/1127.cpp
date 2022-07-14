#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int arr[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  for (int i = 0; i < m; ++i) {
    for (int j = n-1; j != -1; --j) {
      printf("%d ", arr[j][i]);
    }
    printf("\n");
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
