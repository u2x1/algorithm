#include <cstdio>
#include <cstring>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  bool door[n+1]; memset(door, 1, sizeof(door));
  for(int i = 2; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      door[j] = !door[j];
    }
  }

  for(int i = 1; i <= n; ++i) {
    if (door[i]) { printf("%d ", i); }
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
