#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  bool isPrime[100]; memset(isPrime, 1, sizeof(isPrime));
  for (int i = 2; i < 50; ++i) {
    if(isPrime[i]) {
      for(int j = i*2; j < 100; j+=i) {
        isPrime[j] = 0;
      }
    }
  }
  int prime[101]; int pos = 0;
  for (int i = 2; i < 100; ++i) { if (isPrime[i]) { prime[pos++] = i;} }
  int num;
  for (int i = 6; i < 101; i+=2) {
    for (int j = 0; j < pos; ++j) {
      num = prime[j];
      if (isPrime[i - num]) {
        printf("%d=%d+%d\n", i, num, i-num);
        break;
      }
    }
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
