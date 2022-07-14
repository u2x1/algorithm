#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n && scanf("%d", &arr[i]) == 1; ++i);
  int m;
  scanf("%d", &m);


#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == m) { ++sum; }
  }
  printf("%d", sum);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
