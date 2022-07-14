#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int revNum(int num) {
  int ret = 0;
  while (num != 0) {
    ret = (ret*10) + (num%10);
    num /= 10;
  }
  return ret;
}

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  const int l = (n*10+1)/2+0.5;
  const int l2 = n*10;
  bool isPrime[l2]; memset(isPrime, 1, sizeof(isPrime));
  for (int i = 2; i <= l; ++i) {
    if (isPrime[i]) {
      for (int j = i+i; j <= l2; j+=i) {
        isPrime[j] = 0;
      }
    }
  }

  bool flag = true;
  if (m == 1) { m = 2; }
  for (; m <= n; ++m) {
    if(isPrime[m] && isPrime[revNum(m)]) {
      if(flag) { flag = false; }
        else { printf(","); }
      printf("%d", m);
    }
  }
  if(flag) { printf("No"); }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
