#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int arr[10];
  for (int i = 0; i < 10 && scanf("%d", &arr[i]) == 1; ++i);
  int x;
  scanf("%d", &x);
  x+=30;

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  int sum = 0;
  for (int i = 0; i < 10; ++i) {
    if (arr[i] <= x) { ++sum; }
  }
  printf("%d", sum);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
