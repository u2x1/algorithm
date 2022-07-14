#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  bool isPrime[n+1]; memset(isPrime, 1, sizeof(isPrime));
  int l = (n+1)/2+0.5;
  for (int i = 2; i <= l; ++i) {
    if (isPrime[i]) {
      for (int j = i+i; j <= n; j+=i) {
        isPrime[j] = 0;
      }
    }
  }
  if (isPrime[m]) { printf("%d", m); }
  else { for(int i = m-1; i != 1; --i) { if(isPrime[i] && m % i == 0) { printf("%d", i); break; } } }

  ++m;
  for (; m <= n; ++m) {
    if (isPrime[m]) { printf(",%d", m); }
    else { for(int i = m-1; i != 1; --i) { if(isPrime[i] && m % i == 0) { printf(",%d", i); break; } } }
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
