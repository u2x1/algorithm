#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  int vec1[n], vec2[n];
  for (int i = 0; i < n && scanf("%d", &vec1[i]); ++i);
  for (int i = 0; i < n && scanf("%d", &vec2[i]); ++i);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += vec1[i] * vec2[i];
  }
  printf("%d", sum);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
