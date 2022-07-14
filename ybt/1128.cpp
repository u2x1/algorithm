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

  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      if (i == 0 || j == 0 || i == n-1 || j == m-1) {
        printf("%d ", arr[i][j]);
      } else {
        printf("%d ", (int)((arr[i-1][j] + arr[i+1][j]
                 +  arr[i][j-1] + arr[i][j+1]
                 +  arr[i][j])
                 * 1.0 / 5 + 0.5));
      }
    }
    printf("\n");
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
