#include <cstdio>
#include <cstring>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int l, m;
  scanf("%d%d", &l, &m);
  ++l;
  int end[l];
  memset(end, 0, sizeof(end));
  int begin[m];
  int cache1, cache2;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &cache1, &cache2);
    end[cache1] = cache2;
    begin[i] = cache1;
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  int sum = 0;
  for (int i = 0; i < l;) {
    if (end[i] == 0) {
      ++sum; ++i;
    } else {
      i = end[i];
      for (int j = 0; j < m; ++j) {
        int idx = begin[j];
        if (idx <= i && end[idx] >= i) {
          i = 1 + end[idx];
        }
      }
    }
  }
  printf("%d", sum);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
