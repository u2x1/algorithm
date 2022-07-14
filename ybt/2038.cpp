#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  unsigned int arr[n];
  for (int i = 0; i < n && scanf("%u", &arr[i]) == 1; ++i);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  unsigned int max = 0, pos = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > max) { pos = i; max = arr[i]; }
  }
  printf("%d", pos+1);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
