#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  double price[10] { 28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65 };
  double sum = 0;
  int cache;
  for (int i = 0; i < 10; ++i) {
    scanf("%d", &cache);
    sum += 1.0 * cache * price[i];
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  printf("%.1f", sum);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
