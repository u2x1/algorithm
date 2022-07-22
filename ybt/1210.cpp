#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int primes[50]; bool notPrime[100];

void initPrimes() {
  for (int i = 2; i<50; ++i) {
    if (!notPrime[i]) {
      for(int j = i+i; j < 100; j+=i) { notPrime[j] = 1; }
    }
  }
  int pos = -1;
  for (int i = 2; i < 100; ++i) {
    if (!notPrime[i]) {
      primes[++pos] = i;
    }
  }
}

void f(int x, const int pos) {
  int n = 0; const int p = primes[pos];
  while (x % p == 0) {
    x /= p;
    ++n;
  }
  bool flag = 0;
  if (n > 0) {
    printf("%d", p);
    if (n > 1) {
      printf("^%d", n);
    }
    flag = 1;
  }
  if (x != 1) {
    if (flag) { printf("*"); }
    f(x, pos+1); 
  }
}

int main() {
  initPrimes();
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  f(n, 0);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
