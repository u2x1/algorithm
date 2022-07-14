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

  bool isPrime[1000]; memset(isPrime, 1, sizeof(isPrime));
  for (int i = 2; i < 500; ++i) {
    if (isPrime[i]) {
      for (int j = i+i; j < 1000; j+=i){ isPrime[j] = 0; }
    }
  }
  int cnt = 0; int num;
  for (int i = 1; i <= 9; ++i) {
    num = i*10+i;
    if (num > n) break;
    if (isPrime[num]) { ++cnt; }
  }
  for (int i = 1; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      num = i*100+j*10+i;
      if (num > n) break;
      if (isPrime[num]) { ++cnt; }
    }
  }
  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
