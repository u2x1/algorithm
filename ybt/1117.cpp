#include <cstdio>
#include <cstring>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  bool not_exist[5001];
  memset(not_exist, 1, sizeof(not_exist));
  int n;
  scanf("%d", &n);
  int arr[n], cache, i = 0;
  for (int count = 0; count < n && scanf("%d", &cache) == 1; ++count) {
    if (not_exist[cache]) { arr[i++] = cache; not_exist[cache] = 0; }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  for (int j = 0; j != i; ++j) {
    printf("%d ", arr[j]);
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
