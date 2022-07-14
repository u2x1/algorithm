#include <cstdio>
#include <ctime>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  int sum = 0;
  for (int i = 0; i*a <= c; ++i) {
    if ((c-i*a) % b == 0) { ++sum; }
  }
  printf("%d", sum);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
