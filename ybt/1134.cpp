#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  char c = getchar();
  if (c >= '0' && c <= '9') { printf("no"); return 0; }
  do {
    if (  !(c >= 'a' && c <= 'z')
       && !(c >= 'A' && c <= 'Z')
       && !(c >= '0' && c <= '9')
       &&   c != '_') { printf("no"); return 0;}
  }
  while ((c = getchar()) != EOF && c != '\n');

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("yes");

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
