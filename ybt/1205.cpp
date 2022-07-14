#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

void f(int n, char a, char b, char pass) {
  if (!n) { return; }
  f(n-1, a, pass, b);
  printf("%c->%d->%c\n", a, n, b);
  f(n-1, pass, b, a);
}

int main() {
  int n; char a, c, target;
  scanf("%d %c %c %c", &n, &a, &target, &c);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  f(n, a, target, c);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
