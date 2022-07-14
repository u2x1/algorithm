#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
  int n;
  scanf("%d", &n);
  bool isPrime[n+1];
  memset(isPrime, 1, sizeof(isPrime));

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int root = n / 2.0 + 0.5;
  for (int i = 2; i <= root; ++i) {
    if (isPrime[i]) {
      for (int j = i*2; j <= n; j+=i) {
        isPrime[j] = 0;
      }
    }
  }
  int sum = 1;
  for(int i = 3; i <= n; ++i) {
    if (isPrime[i]) {
      ++sum;
    }
  }
  printf("%d", sum);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
