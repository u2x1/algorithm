#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int vec1[n][m], vec2[m][k];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &vec1[i][j]);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      scanf("%d", &vec2[i][j]);
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif
  
  int rst[n][k];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
        rst[i][j] = 0;
      for (int z = 0; z < m; ++z) {
        rst[i][j] += vec1[i][z] * vec2[z][j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d", rst[i][0]);
    for (int j = 1; j < k; ++j) {
      printf(" %d", rst[i][j]);
    }
    printf("\n");
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
