#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int x, y;
  scanf("%d%d", &x, &y);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  bool isPrime[y+1]; memset(isPrime, 1, sizeof(isPrime));
  const int l = (y+1)/2+0.5;
  for (int i = 2; i < l; ++i) {
    if (isPrime[i]) {
      for (int j = i+i; j <= y; j+=i) {
        isPrime[j] = 0;
      }
    }
  }
  int cnt = 0;
  if (x == 1) { x = 2; }
  for (; x <= y; ++x) { if(isPrime[x]) { ++cnt; } }
  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
