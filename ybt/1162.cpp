#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

void revPrint(char *s) {
  if (*s == '!') { return; }
  revPrint(s+1);
  putchar(*s);
}

int main() {
  char s[10000];
  scanf("%s", s);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  revPrint(s);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
