#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

bool notPrime[1000];
int main() {

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for (int i = 2; i < 499; ++i) {
    if (!notPrime[i]) {
      for (int j = i*2; j <= 999; j+=i) { notPrime[j] = 1; }
    }
  }
  int num;
  for (int i = 1; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      num = i*100+j*10+i;
      if(notPrime[num]) { continue; }
      printf("%d\n", num);
    }
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
