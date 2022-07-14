#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  bool isPrime[n+1];
  memset(isPrime, 1, sizeof(isPrime));
  int l = n / 2 + 0.5;
  for (int i = 2; i <= l; ++i) {
    if (isPrime[i]) {
      for (int j = i+i; j <= n; j+=i) {
        isPrime[j] = 0;
      }
    }
  }
  for (int i = 3; i < n - 1; i+=2) {
    if (isPrime[i] && isPrime[i+2]) {
      printf("%d %d\n", i, i+2);
    }
  }

  if(n < 5) { printf("empty"); }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
