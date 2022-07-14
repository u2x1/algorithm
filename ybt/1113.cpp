#include <cstdio>
#include <climits>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  int max = INT_MIN, cache, max_num_count, sum = 0;
  for (int i = 0; i < n && scanf("%d", &cache) == 1; ++i) {
    sum += cache;
    if (cache > max) {
      max_num_count = 1;
      max = cache;
    } else if (cache == max) {
      ++max_num_count;
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  printf("%d", sum - max*max_num_count);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
