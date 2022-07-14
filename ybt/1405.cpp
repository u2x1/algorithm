#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int s;
  scanf("%d", &s);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  bool isPrime[s]; memset(isPrime, 1, sizeof(isPrime));
  int l = s/2+0.5;
  for (int i = 2; i <= l; ++i) {
    if (isPrime[i]) {
      for (int j = i+i; j < s; j+=i) { isPrime[j] = 0; }
    }
  }
  int product = 0, cache;
  for (int i = 2; i <= l; ++i) {
    if (isPrime[i] && isPrime[s-i]) {
      if ((cache = i*(s-i)) > product) {
        product = cache;
      }
    }
  }
  printf("%d", product);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
