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

  bool isPrime[n];
  memset(isPrime, 1, sizeof(isPrime));
  for(int i = 2; i < n; ++i) {
    if (isPrime[i]) {
      for (int j = i*2; j < n; j+=i) {
        isPrime[j] = 0;
      }
    }
  }
  for (int i = 2; i < n; ++i) {
    if (isPrime[i]) {
      printf("%d\n", i);
    }
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
