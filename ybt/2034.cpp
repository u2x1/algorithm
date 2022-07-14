#include <cstdio>
#include <ctime>

int main() {
  int x;
  while (scanf("%d", &x) != EOF) {
    printf("%d ", x);
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
