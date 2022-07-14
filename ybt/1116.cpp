#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  int curr, currLen = 0, maxLen = 0, cache;
  for (int i = 0; i < n && scanf("%d", &cache); ++i) {
    if (cache == curr) {
      ++currLen;
    } else {
      if (currLen > maxLen) { maxLen = currLen; }
      currLen = 1;
      curr = cache;
    }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  if (currLen > maxLen) { maxLen = currLen; }
  printf("%d", maxLen);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
