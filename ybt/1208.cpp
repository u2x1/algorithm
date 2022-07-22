#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

void f(int x) {
  int pos = 0; int tmp = 1;
  while(tmp < x) { tmp <<= 1; ++pos; }
  if (tmp != 1 && tmp != x) { tmp >>= 1; --pos; }

  putchar('2');
  if (pos != 1) {
    putchar('(');
    if (pos == 0 || pos == 2) {
      putchar(pos + '0');
    } else {
      f(pos);
    }
    putchar(')');
  }
  x -= tmp;
  if (x > 0) { putchar('+'); f(x); }
}

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  f(n);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
