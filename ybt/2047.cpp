#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {

  char str[200];
  while (scanf("%s", str) != EOF) {
    printf("%s ", str);
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
