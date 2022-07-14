#include <cstdio>
#include <climits>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int arr[5][5], cache;
  int line_max_idx[5], max;
  for(int i = 0; i < 5; ++i) {
    max = INT_MIN;
    for(int j = 0; j < 5; ++j) {
      scanf("%d", &cache);
      if (cache > max) { max = cache; line_max_idx[i] = j; }
      arr[i][j] = cache;
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif


  int min, min_col_idx, min_row_idx;
  for(int i = 0; i < 5; ++i) {
    min = INT_MAX;
    for(int j = 0; j < 5; ++j) {
      cache = arr[j][i];
      if (cache < min) { min = cache; min_row_idx = j; min_col_idx = i; }
    }
    if (line_max_idx[min_row_idx] == min_col_idx) {
      printf("%d %d %d", 1+min_row_idx, 1+min_col_idx, min);
      return 0;
    }
  }
  printf("not found");

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
