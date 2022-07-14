#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  bool isPrime[100];
  isPrime[0] = 0; isPrime[1] = 0;
  memset(isPrime, 1, sizeof(isPrime));
  for (int i = 2; i < 50; ++i) {
    if (isPrime[i]) {
      for (int j = i+i; j < 100; j+=i) { isPrime[j] = 0; }
    }
  }
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (isPrime[i*10+j] && isPrime[j*10+i]) { printf("%d\n", i*10+j); }
    }
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
