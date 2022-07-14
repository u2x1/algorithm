#include <cstdio>
#include <cstring>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  bool lights[n+1];
  memset(lights, 0, sizeof(lights));
  for (int i = 2; i <= m; ++i) {
    for(int j = i; j <= n; j += i) {
      lights[j] = !lights[j];
    }
  }

  printf("1");
  for (int i = 2; i <= n; ++i) {
    if (!lights[i]) {
      printf(",%d", i);
    }
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
