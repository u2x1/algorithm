#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n && scanf("%d", &arr[i]); ++i);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  for (int i = 1; i < n && printf("%d ", arr[i]); ++i);
  printf("%d", arr[0]);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
