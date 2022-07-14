#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n && scanf("%d", &arr[i]); ++i);
  int target;
  scanf("%d", &target);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  for (int i = 0; i < n; ++i) {
    if (arr[i] == target) { printf("%d", i +1); return 0; }
  }
  printf("-1");

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
