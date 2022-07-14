#include <cstdio>
#include <ctime>

int main() {
  int d;
  scanf("%d", &d);
  int sum = 0;

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  int dayleft = d;
  for (int i = 1; dayleft > i; ++i) {
    sum += dayleft;
    dayleft -= i;
  }

  printf("%d", sum+dayleft);
#ifdef BENCHMARK
  printf("\n  runtime: %f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif
  return 0;
}
